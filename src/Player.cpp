//
// Created by maxhe on 11/13/2025.
//

#include "../include/Player.h"


// Really simple class honestly lol
void Player::addCard(const Card &card) {
    hand.addCard(card);
}

void Player::clearHand() {
    hand.clear();
}

Hand& Player::getHand() {
    return hand;
}


