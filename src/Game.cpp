//
// Created by maxhe on 11/13/2025.
//

#include "../include/Game.h"


void Game::dealInitialCards() {
    /* we shuffle the deck (this could also be done in the run loop) */
    player.clearHand(); // reset the hands because *BIG* Surprise! if you dont they wont disapear when the game restarts
    dealer.clearHand();

    deck.shuffle();

    int count = 0;

    while (count < 2) {
        player.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());
        count++;
    }
}

Hand Game::getDealerHand() {
    return dealer.getHand();

}

Hand Game::getPlayerHand() {
    return player.getHand();
}


/**Legacy */
void Game::showHands(bool revealDealer){

    std::cout << "Player Hand: " << player.getHand().toString() << std::endl;

    if (revealDealer) {
        std::cout << "Dealer Hand: " << dealer.getHand().toString() << std::endl;

    }
    else {
        std::cout << "Dealer Hand: " << dealer.getHand().hiddenToString() << std::endl;

    }
}



Result Game::determineResult() {
    if (player.getHand().isBlackjack()) return Result::PlayerBlackjack;
    if (dealer.getHand().isBlackjack()) return Result::DealerBust;
    if (player.getHand().isBust()) return Result::PlayerBust;
    if (dealer.getHand().isBust()) return Result::DealerBust;
    if (dealer.getHand().getBestTotal() > player.getHand().getBestTotal()) return Result::DealerWins;
    if (dealer.getHand().getBestTotal() < player.getHand().getBestTotal()) return Result::PlayerWins;

    return Result::noResult;


}

int Game::getDealerTotal() {
    return dealer.getHand().getBestTotal();
}

void Game::playerAction(Action action) {
    if (action == Action::Hit) {
        player.addCard(deck.dealCard());
    }

}

void Game::dealerAction() { // dealer does not need action parameter
    dealer.addCard(deck.dealCard());
}




/*void Game::run() {
    dealInitialCards();
    if (player.getHand().isBlackjack()) {
        showHands(true);
        std::cout << "Player Wins" << std::endl;

    }
    else if (dealer.getHand().isBlackjack()) {
        showHands(true);
        std::cout << "Dealer Wins" << std::endl;
    }
    else{

    showHands();
    playerTurn();
    showHands(true);
        if (player.getHand().isBlackjack()) {

            std::cout << "Player Wins" << std::endl;

        }
        else if (player.getHand().isBust()) {
            std::cout << "Bust!" << std::endl;

        }
        else {
            dealerTurn();
            showHands(true);
            if (dealer.getHand().isBlackjack()) {
                std::cout << "Dealer Wins" << std::endl;
            }
            else if (dealer.getHand().isBust()) {
                std::cout << "Dealer Bust!" << std::endl;
            }
            else {
                showHands(true);
                determineResult();

            }



        }
    }


}*/




