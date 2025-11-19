//
// Created by maxhe on 11/17/2025.
//

#include "../include/GameApp.h"
using namespace sf;


std::string GameApp::mapCardTexture(Rank rank , Suit suit) {
  std::string pathToCard = "../assets/Cards/";
  switch(suit){
    case Suit::Clubs:
      pathToCard += "Clubs/";
    break;
    case Suit::Diamonds:
      pathToCard += "Diamonds/";
    break;
    case Suit::Hearts:
      pathToCard += "Hearts/";
    break;
    case Suit::Spades:
      pathToCard += "Spades/";
    break;
    default:
      break;
  }

  switch(rank){
    case Rank::Two:
      pathToCard += "2";
    break;
    case Rank::Three:
      pathToCard += "3";
    break;
    case Rank::Four:
      pathToCard += "4";
    break;
    case Rank::Five:
      pathToCard += "5";
    break;
    case Rank::Six:
      pathToCard += "6";
    break;
    case Rank::Seven:
      pathToCard += "7";
    break;
    case Rank::Eight:
      pathToCard += "8";
    break;
    case Rank::Nine:
      pathToCard += "9";
    break;
    case Rank::Ace:
      pathToCard += "A";
    break;
    case Rank::Jack:
      pathToCard += "J";
    break;
    case Rank::Queen:
      pathToCard += "Q";
    break;
    case Rank::King:
      pathToCard += "K";
    break;
    default:
      break;
  }


  pathToCard += ".png";
  return pathToCard;

}

void GameApp::handleInput(const sf::Event& event, gameState& state) {
  if (game.determineResult() != Result::PlayerBlackjack && game.determineResult() != Result::PlayerBust) {
      if (event.type == sf::Event::KeyPressed && state ==  gameState::playerTurn) {
          if (event.key.code == sf::Keyboard::H) game.playerAction(Action::Hit);
          if (event.key.code == sf::Keyboard::S) state = gameState::dealerTurn;

      }
    }

  else {
     state = gameState::roundEnd;
  }


}

void GameApp::dealerTurn(gameState& state) {
  if (game.determineResult() != Result::DealerBlackjack && game.determineResult() != Result::DealerBust) {
        if (game.getDealerTotal() < 17){
              game.dealerAction();

            }
            else {
            state = gameState::roundEnd;
            }
        }
  else {
        state = gameState::roundEnd;
    }

}

void GameApp::updateCards() {
  Hand d = game.getDealerHand();
  Hand p = game.getPlayerHand();
  if (d.getHandLength() > 0 || p.getHandLength() > 0) { // i feel like wiping every time cards gets updated may be ineffiecnet but its also safer than potentially running into bugs where the card sprites hang in memory
    PlayerCards.clear();
    DealerCards.clear();
    CardTexturePlayer.clear();
    CardTextureDealer.clear();

  }

  for (int i = 0; i < d.getHandLength(); i++) { // having two seperate for loops for the two vectors is inefficent, will find a better way
    sf::Texture texture;
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

void GameApp::renderCards(bool revealDealer) {
  int posX = 100;
  int const posY = 800;
  for (int i = 0; i < PlayerCards.size(); i++) {
    PlayerCards[i].setPosition(posX, posY);
    PlayerCards[i].setTexture(CardTexturePlayer[i]);
    window.draw(PlayerCards[i]);
    posX += 100;
  }

  int posXD = 100;
  int const posYD = 200;
  for (int i = 0; i < DealerCards.size(); i++) {

    DealerCards[i].setPosition(posXD, posYD);
    if (i == 0 && !revealDealer) {
      sf::Texture texture;
      texture.loadFromFile("../assets/Cards/Back_Red.png");
      DealerCards[i].setTexture(texture);
    }
    else {
      DealerCards[i].setTexture(CardTextureDealer[i]);
    }
    window.draw(DealerCards[i]);
    posXD += 100;
  }





}

void GameApp::updateGame(gameState& state, sf::Text& player, sf::Text& dealer, sf::Text& winner) {

  switch (state) { // we loop through each potential state to see what the game needs to do at this point
    case gameState::roundStart:
      game.dealInitialCards();
      player.setString(game.getPlayerHand().toString());
      dealer.setString(game.getDealerHand().toString());






    state = gameState::playerTurn;
      break;
    case gameState::playerTurn:
      player.setString(game.getPlayerHand().toString());
      dealer.setString(game.getDealerHand().toString());
      break;
    case gameState::dealerTurn:
      dealerTurn(state);
    revealDealer = true;
      player.setString(game.getPlayerHand().toString());
      dealer.setString(game.getDealerHand().toString());
      break;
    case gameState::roundEnd:
      player.setString(game.getPlayerHand().toString());
    dealer.setString(game.getDealerHand().toString());

      Result r = game.determineResult();
      if (r == Result::PlayerBlackjack) {
        winner.setString("Player blackjack");
      }
      else if (r == Result::PlayerBust) {
        winner.setString("Player bust");
      }
      else if (r == Result::DealerBlackjack) {
        winner.setString("Dealer blackjack");
      }
      else if (r == Result::DealerBust) {
        winner.setString("Dealer bust");
      }
      else if (r == Result::DealerWins) {
        winner.setString("Dealer wins");
      }
      else if (r == Result::PlayerWins) {
        winner.setString("Player wins");

      }
      else {
        winner.setString("idk");
      }
      break;

  }
}




void GameApp::run(){
    window.create(sf::VideoMode(1600, 1200), "Blackjack v0.0.1 Alpha");

    sf::Font font;
    sf::Text dealerText;
    sf::Text playerText;
    sf::Text winText;
    gameState gameState = gameState::roundStart;

    font.loadFromFile("DejaVuSans.ttf");
    dealerText.setFont(font);
    dealerText.setCharacterSize(20);
    playerText.setFont(font);
    playerText.setCharacterSize(20);
    playerText.setString("Player");
    dealerText.setString("Dealer");

    playerText.setFillColor(sf::Color::Red);
    dealerText.setFillColor(sf::Color::Red);

    playerText.setPosition(100, 1100);
    dealerText.setPosition(100, 100);

    winText.setFont(font);
    winText.setCharacterSize(20);
    winText.setFillColor(sf::Color::Red);

    winText.setPosition(800, 600);



  sf::Sprite sprite;
  sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));



  CardTexture cardTexture;






    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {

          handleInput(event, gameState); // I was very stupid and oringally left this function outsie of the poll event loop, and was stuck wondering why it wasnt working lmao

            if (event.type == sf::Event::Closed)
                window.close();
        }




        window.clear();
        updateGame(gameState, playerText, dealerText, winText);
        updateCards();
        renderCards(revealDealer);
        window.draw(winText);



        window.display();






    }
}




