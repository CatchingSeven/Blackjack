//
// Created by maxhe on 11/17/2025.
//

#ifndef GAMEAPP_H
#define GAMEAPP_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"


extern std::map<sf::Event, Action> mapActions;

enum class gameState {
  roundStart,
  playerTurn,
  dealerTurn,
  roundEnd
};

class GameApp {
  private:
    sf::RenderWindow window;
    Game game;
    Hand dealerHand;
    Hand playerHand;
    void handleInput(const sf::Event& event, gameState& state);
    void updateGame(gameState& state, sf::Text& playerText, sf::Text& dealerText,  sf::Text& winText);
    void dealerTurn(gameState& state);



  public:
    void run();



};



#endif //GAMEAPP_H
