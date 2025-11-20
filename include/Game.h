//
// Created by maxhe on 11/13/2025.
//

#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
enum class Result {
  DealerBlackjack,
  PlayerBlackjack,
  DealerBust,
  PlayerBust,
  DealerWins,
  PlayerWins,
  noResult
};

enum class Action {
  Hit,
  Stand,
  DoubleDown,
  Split
};
class Game {
private:
  Deck deck;
  Player player;
  Player dealer;
  bool playerWins;


public:
  void dealInitialCards();
  void playerAction(Action action);//Player turn takes in action.
  void dealerAction();
  int getDealerTotal();// used just as a wrapper to check if dealer is at 17 which forces them to stand
  void showHands(bool revealDealer = false);
  Hand getDealerHand();
  Hand getPlayerHand();
  Result determineResult();
  void run();





};



#endif //GAME_H
