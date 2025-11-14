//
// Created by maxhe on 11/13/2025.
//

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include "card.h"
#include <algorithm>
#include <random>


class Deck {
  private:
    std::vector<Card> cards;
    int currentIndex;
  public:
    Deck();

    void shuffle();
    Card dealCard();
    bool isEmpty() const;
    void print();


};



#endif //DECK_H
