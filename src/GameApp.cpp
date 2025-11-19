//
// Created by maxhe on 11/17/2025.
//

#include "../include/GameApp.h"
using namespace sf;
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

void GameApp::updateGame(gameState& state, sf::Text& player, sf::Text& dealer, sf::Text& winner) {

  switch (state) {
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



    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {

          handleInput(event, gameState);

            if (event.type == sf::Event::Closed)
                window.close();
        }




        window.clear();
        updateGame(gameState, playerText, dealerText, winText);
        window.draw(dealerText);
        window.draw(playerText);
        window.draw(winText);


        window.display();






    }
}




