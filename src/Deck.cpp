//
// Created by maxhe on 11/13/2025.
//

#include "../include/Deck.h"





/* Could this be better? */
Deck::Deck() {
    currentIndex = 0;
    cards.reserve(52);

    

    for (int i = 0; i < 4; i++) {
        for (int j = 2; j <= 14; j++) {
            Card c( static_cast<Suit>(i), static_cast<Rank>(j) );
            cards.push_back(c);

        }

    }
}


void Deck::shuffle()
{
    currentIndex = 0; // reset current index to simulate all cards being added back to the deck before shuffling
        std::random_device rd;
        std::default_random_engine rng(rd());
        std::shuffle(cards.begin(), cards.end(), rng);
    }

Card Deck::dealCard() {
    Card c = cards[currentIndex];
    currentIndex++; // we increment for every card dealt this turn to ensure the same card cant be drawn twice on the same turn

    return c;
}






void Deck::print() {
    for (int i = 0; i < cards.size(); i++) {
        Card c = cards[i];
        std::cout << c.getName() << std::endl;
    }
}

bool Deck::isEmpty() const {
    if (currentIndex == cards.size()) return true;
    return false;

}
