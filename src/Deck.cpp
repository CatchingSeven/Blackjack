//
// Created by maxhe on 11/13/2025.
//

#include "../include/Deck.h"






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
        std::random_device rd;
        std::default_random_engine rng(rd());
        std::shuffle(cards.begin(), cards.end(), rng);
    }






void Deck::print() {
    for (int i = 0; i < cards.size(); i++) {
        Card c = cards[i];
        std::cout << c.getName() << std::endl;
    }
}
