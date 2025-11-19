//
// Created by maxhe on 11/17/2025.
//

#ifndef GAMEAPP_H
#define GAMEAPP_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include "CardTexture.h"


extern std::map<sf::Event, Action> mapActions;

enum class gameState {
  roundStart,
  playerTurn,
  dealerTurn,
  roundEnd
};

extern std::map<Rank, std::string> RankToTexture;


class GameApp {
  private:
    sf::RenderWindow window;
    Game game;
    bool revealDealer;
    std::vector<sf::Sprite> PlayerCards;
    std::vector<sf::Sprite> DealerCards;
    std::vector<sf::Texture> CardTexturePlayer;
    std::vector<sf::Texture> CardTextureDealer;
    std::string mapCardTexture(Rank rank, Suit suit);
    void handleInput(const sf::Event& event, gameState& state);
    void updateGame(gameState& state, sf::Text& playerText, sf::Text& dealerText,  sf::Text& winText);
    void dealerTurn(gameState& state);
    void updateCards();
    void renderCards(bool revealDealer = false);


  public:
    void run();



};



#endif //GAMEAPP_H
