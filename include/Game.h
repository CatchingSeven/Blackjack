//
// Created by maxhe on 11/13/2025.
//

#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"

class Game {
private:
  Deck deck;
  Player player;
  Player dealer;
  bool playerWins;

  void dealInitialCards();
  void playerTurn();
  void dealerTurn();
  void showHands(bool revealDealer = false);
  void determineResult();
public:
  void run();



};



#endif //GAME_H
