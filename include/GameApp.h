//
// Created by maxhe on 11/17/2025.
//

#ifndef GAMEAPP_H
#define GAMEAPP_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include "SettingsMenu.h"
#include <string.h>;



extern std::map<sf::Event, Action> mapActions;

enum class gameState {
  mainMenu,
  settings,
  roundStart,
  playerTurn,
  dealerTurn,
  roundEnd
};






extern std::map<Rank, std::string> RankToTexture;

extern std::map<Suit, std::string> SuitToDir;
extern std::map<Rank, std::string> RankToImage;







class GameApp {
  private:
  Settings settings;

    sf::RenderWindow window;
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    sf::Texture settingsTexture;
    sf::Texture playTexture;

    sf::Font font;
    sf::Text restart;
    sf::Text winText;
    sf::Text title;
    sf::Text dealerScore;
    sf::Text playerScore;

    gameState gameState;
    sf::Sprite playButton;
    sf::Sprite settingsButton;
    sf::Sprite statsButton;
    float width;
    float height;






    float const scaleX = 0.5f;
    float const scaleY = 0.5f;

    Game game;
    bool revealDealer;
    std::vector<sf::Sprite> PlayerCards;
    std::vector<sf::Sprite> DealerCards;
    std::vector<sf::Texture> CardTexturePlayer;
    std::vector<sf::Texture> CardTextureDealer;
    void loadAssets();
    void mainMenu();
    void play();
    void handleInput(const sf::Event& event);
    void updateGame();
    void dealerTurn();
    void updateCards(bool revealDealer = false);
    void renderCards();
    void clear();
    void display();



  public:
    void run();



};



#endif //GAMEAPP_H
