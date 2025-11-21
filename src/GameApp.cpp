//
// Created by maxhe on 11/17/2025.
//

#include "../include/GameApp.h"
using namespace sf;


std::map<Suit, std::string> SuitToDir = {
  {Suit::Clubs, "Clubs/"},
{Suit::Diamonds, "Diamonds/"},
{Suit::Hearts, "Hearts/"},
{Suit::Spades, "Spades/"},



};
std::map<Rank, std::string> RankToImage = {
  {Rank::Two, "2.png"},
{Rank::Three, "3.png"},
{Rank::Four, "4.png"},
{Rank::Five, "5.png"},
{Rank::Six, "6.png"},
{Rank::Seven, "7.png"},
{Rank::Eight, "8.png"},
{Rank::Nine, "9.png"},
{Rank::Ten, "10.png"},
{Rank::Jack, "J.png"},
{Rank::Queen, "Q.png"},
{Rank::King, "K.png"},
{Rank::Ace, "A.png"},

};

/** Helpers */
static std::string mapCardTexture(Rank rank , Suit suit) {

  return "../assets/Cards/"+SuitToDir[suit]+RankToImage[rank];

}

static std::string resultToString(Result result) {
  switch (result) {
    case Result::PlayerBlackjack: return "Blackjack";
    case Result::PlayerBust: return "Player Bust";
    case Result::PlayerWins: return "Player Wins";
    case Result::DealerBlackjack: return "Dealer Blackjack";
    case Result::DealerBust: return "Dealer Bust";
    case Result::DealerWins: return "Dealer Wins";
  }
  return "No Winner?";
}














/** GameApp definitions */

void GameApp::handleInput(const sf::Event& event) {

      if (event.type == sf::Event::KeyPressed && gameState ==  gameState::playerTurn) {
          if (event.key.code == sf::Keyboard::H) game.playerAction(Action::Hit);
          if (event.key.code == sf::Keyboard::S) gameState = gameState::dealerTurn;

      }

     if (event.type == sf::Event::KeyPressed && gameState ==  gameState::roundEnd) {
       if (event.key.code == sf::Keyboard::Y) gameState = gameState::roundStart;
       if (event.key.code == sf::Keyboard::Q) gameState = gameState::mainMenu;

     }

    if (gameState ==  gameState::mainMenu) {
      if (event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        if (playButton.getGlobalBounds().contains(mouse.x,mouse.y)) {
          gameState = gameState::roundStart;
        }


      }
    }
    }






void GameApp::dealerTurn() {

        if (game.getDealerTotal() < 17){
              game.dealerAction();

            }
            else {
            gameState = gameState::roundEnd;
            }



}

void GameApp::updateCards(bool revealDealer) {
  Hand d = game.getDealerHand();
  Hand p = game.getPlayerHand();


  for (int i = 0; i < d.getHandLength(); i++) { // having two seperate for loops for the two vectors is inefficent, will find a better way
    sf::Texture texture;
    if (!revealDealer&&i==0) texture.loadFromFile("../assets/Cards/Back_Red.png");
    texture.loadFromFile(mapCardTexture(d.getCardRank(i), d.getCardSuit(i))); // essentially, we use a method that returns a string here, this string constructs a path to the relevent texture
    CardTextureDealer.push_back(texture);
    sf::Sprite sprite;
    DealerCards.push_back(sprite);
  }

  for (int i = 0; i < p.getHandLength(); i++) {
    sf::Texture texture;
    texture.loadFromFile(mapCardTexture(p.getCardRank(i), p.getCardSuit(i)));
    CardTexturePlayer.push_back(texture);
    sf::Sprite sprite;

    PlayerCards.push_back(sprite);

  }



}

void GameApp::renderCards() {
  int step = window.getSize().x / 10;
  int playerCardPosX = step;
  int const playerCardPosY = window.getSize().y - window.getSize().y / 3;
  int dealerCardPosX = window.getSize().x / 10;
  int const dealerCardPosY = window.getSize().y / 8;


  for (int i = 0; i < PlayerCards.size(); i++) {
    PlayerCards[i].setPosition(playerCardPosX, playerCardPosY);
    PlayerCards[i].setTexture(CardTexturePlayer[i]);
    PlayerCards[i].setScale(scaleX, scaleY);
    window.draw(PlayerCards[i]);
    playerCardPosX += step;
  }



  for (int i = 0; i < DealerCards.size(); i++) {

    DealerCards[i].setPosition(dealerCardPosX, dealerCardPosY);
    DealerCards[i].setTexture(CardTextureDealer[i]);
    DealerCards[i].setScale(scaleX, scaleY);
    window.draw(DealerCards[i]);
    dealerCardPosX += step;
  }









}
void GameApp::clear() {
  // This is not recursion obviously
  PlayerCards.clear();
  DealerCards.clear();
  CardTexturePlayer.clear();
  CardTextureDealer.clear();
  winText.setString("");
  restart.setString("");
  window.clear();

}


void GameApp::display() {

  renderCards();
  window.draw(winText);
  window.draw(restart);

  window.display();

}

void GameApp::updateGame() {

  switch (gameState) { // we loop through each potential state to see what the game needs to do at this point
    case gameState::roundStart:
      revealDealer = false;
      game.dealInitialCards();
      if (game.determineResult() != Result::PlayerBlackjack && game.determineResult() != Result::PlayerBust) {
        gameState = gameState::playerTurn;
      }
      else {
        gameState = gameState::roundEnd;
      }
      break;
    case gameState::playerTurn:
      if (game.determineResult() == Result::PlayerBlackjack || game.determineResult() == Result::PlayerBust) gameState = gameState::roundEnd;
      break;
    case gameState::dealerTurn:
      revealDealer = true;
    if (game.determineResult() != Result::DealerBlackjack && game.determineResult() != Result::DealerBust) {
      dealerTurn();
    }
    else {
      gameState = gameState::roundEnd;
    }


      break;
    case gameState::roundEnd:
      revealDealer = true;

      winText.setString(resultToString(game.determineResult()));
      restart.setString("Play Again? (Y to continue Q to quit)");

      break;

  }
}

void GameApp::mainMenu() {
  window.draw(playButton);
  window.draw(title);





}

void GameApp::loadAssets() {

  /* We load all assets in here at the start This just makes the run method much cleaner*/

  /* Menu assets */
  font.loadFromFile("../assets/Fonts/DejaVuSans.ttf");
  title.setFont(font);
  title.setFillColor(sf::Color::Red);
  title.setCharacterSize(100);
  title.setString("Blackjack");
  title.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height / 2);
  title.setPosition(window.getSize().x/2, window.getSize().y/2-200);


  missingTexture.loadFromFile("../assets/UI-Elements/PlayButton.png");
  playButton.setTexture(missingTexture);
  playButton.setScale(scaleX, scaleY);
  playButton.setOrigin(playButton.getLocalBounds().width / 2, playButton.getLocalBounds().height / 2);
  playButton.setPosition((window.getSize().x/2), (window.getSize().y / 2));


  /* Game Assets */

  winText.setFont(font);
  winText.setCharacterSize(30);
  winText.setFillColor(sf::Color::Red);

  restart.setFont(font);
  restart.setCharacterSize(30);
  restart.setFillColor(sf::Color::Red);
  winText.setOrigin(winText.getLocalBounds().width / 2, winText.getLocalBounds().height / 2);
  winText.setPosition(window.getSize().x/2, window.getSize().y/2);

}





void GameApp::run(){
    window.create(sf::VideoMode(1280, 720), "Blackjack v0.1.1 Alpha - Menu Additions");
    loadAssets();
  /* Background */
  background.setSize((sf::Vector2f(window.getSize())));


  background.setFillColor(sf::Color(50, 200, 50));




    gameState = gameState::mainMenu;





    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {

          handleInput(event); // I was very stupid and oringally left this function outsie of the poll event loop, and was stuck wondering why it wasnt working lmao

            if (event.type == sf::Event::Closed)
                window.close();
        }






        clear();
        window.draw(background);


        if (gameState == gameState::mainMenu) {
          mainMenu();

        }
        else {
          updateCards();
          updateGame();
        }



        display();












    }
}




