//
// Created by maxhe on 11/13/2025.
//

#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>

class Hand {
  private:
    std::vector<Card> hand;
  public:
    void addCard(const Card& card);
    int getBestTotal() const;
    bool isBust() const;
    bool isBlackjack() const;
    std::string toString() const;
    void clear();

};



#endif //HAND_H
