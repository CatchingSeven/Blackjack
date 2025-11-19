//
// Created by maxhe on 11/19/2025.
//

#ifndef CARDTEXTURE_H
#define CARDTEXTURE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"


class CardTexture {
  private:
    sf::Texture texture;
    sf::Sprite sprite;
public:

    void setTexture(std::string pathToCard);

};



#endif //CARDTEXTURE_H
