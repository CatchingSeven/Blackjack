//
// Created by maxhe on 11/13/2025.
//

#include "../include/Hand.h"


void Hand::addCard(const Card &card) {
    hand.push_back(card);
}

int Hand::getBestTotal() const {
    int aces = 0;
    int score = 0;
    for (int i = 0; i < hand.size(); i++) {

        if (hand[i].getValue() == 11) {
            aces++;
        }
        score += hand[i].getValue();


    }
    if (score > 21&& aces > 0) {
        while (aces > 0) {
            score -= 10;
            aces--;
        }
    }

    return score;
}


bool Hand::isBust() const{
    return getBestTotal() > 21;
}

bool Hand::isBlackjack() const {
    return getBestTotal() == 21;
}

std::string Hand::toString() const {
    std::string output = "";
    for (int i = 0; i < hand.size(); i++) {
        output += hand[i].getName() + ", ";
    }

    return output;

}


void Hand::clear() {
    hand.clear();
}

