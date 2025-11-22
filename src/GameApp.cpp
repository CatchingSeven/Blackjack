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

  if (gameState ==  gameState::playerTurn) {
    if (event.type == sf::Event::KeyPressed ) {
      if (event.key.code == sf::Keyboard::H) game.playerAction(Action::Hit);
      if (event.key.code == sf::Keyboard::S) gameState = gameState::dealerTurn;

    }

  }
  if (gameState ==  gameState::roundEnd) {
    if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Y) gameState = gameState::roundStart;
      if (event.key.code == sf::Keyboard::Q) gameState = gameState::mainMenu;

    }

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
  dealerScore.setString("");
  playerScore.setString("");
  window.clear();

}


void GameApp::display() { // for whatever reason putting background in here seems to break it and force background to display
  window.draw(winText);
  window.draw(restart);
  window.draw(dealerScore);
  window.draw(playerScore);

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
  width = window.getSize().x;
  height = window.getSize().y;
  /* Background */
  backgroundTexture.loadFromFile("../assets/Background-Images/Background.jpg");
  background.setSize((sf::Vector2f(window.getSize())));
  background.setTexture(&backgroundTexture);

  /* Menu assets */
  font.loadFromFile("../assets/Fonts/DejaVuSans.ttf");
  title.setFont(font);
  title.setFillColor(sf::Color::Red);
  title.setCharacterSize(100);
  title.setString("Blackjack");
  title.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height / 2);
  title.setPosition(width/2.f, (width/2.f)*0.5f);


  missingTexture.loadFromFile("../assets/UI-Elements/PlayButton.png");
  playButton.setTexture(missingTexture);
  playButton.setScale(scaleX, scaleY);
  playButton.setOrigin(playButton.getLocalBounds().width / 2, playButton.getLocalBounds().height / 2);
  playButton.setPosition(width/2.f, (height/2.f)*1.2f);


  /* Game Assets */

  winText.setFont(font);
  winText.setCharacterSize(30);
  winText.setFillColor(sf::Color::White);

  restart.setFont(font);
  restart.setCharacterSize(30);
  restart.setFillColor(sf::Color::White);
  winText.setOrigin(winText.getLocalBounds().width / 2, winText.getLocalBounds().height / 2);
  winText.setPosition(width/2, height/2);

  dealerScore.setFont(font);
  dealerScore.setCharacterSize(30);
  dealerScore.setFillColor(sf::Color::White);
  dealerScore.setOrigin(dealerScore.getLocalBounds().width / 2, dealerScore.getLocalBounds().height/2);
  dealerScore.setPosition(width*0.05f, height*0.05f);

  playerScore.setFont(font);
  playerScore.setCharacterSize(30);
  playerScore.setFillColor(sf::Color::White);
  playerScore.setOrigin(playerScore.getLocalBounds().width / 2, playerScore.getLocalBounds().height/2);
  playerScore.setPosition(width*0.05f, height*0.95f);

}





void GameApp::run(){
  window.create(sf::VideoMode(1920, 1080), "Blackjack v0.1.3 Alpha - Scores Addition");
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);
  std::cout << window.getSystemHandle() << std::endl;



  loadAssets();





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

      if (gameState == gameState::mainMenu) {
        window.draw(background);
        mainMenu();
      }
      else {
        updateGame();
        updateCards();
        window.draw(background);//putting background before we draw other assets in these statements seems to fix the bacground issues... I wonder why?
        renderCards();


        dealerScore.setString("Dealer Score: " + game.getDealerCardValue());
        playerScore.setString("Player Score: " + game.getPlayerCardValue());
      }




        display();//However, putting text in drawing in display is fine?












    }
}




