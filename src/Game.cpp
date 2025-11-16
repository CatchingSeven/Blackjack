//
// Created by maxhe on 11/13/2025.
//

#include "../include/Game.h"


void Game::dealInitialCards() {
    /* we shuffle the deck (this could also be done in the run loop) */
    deck.shuffle();

    int count = 0;

    while (count < 2) {
        player.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());
        count++;
    }
}

void Game::playerTurn() {
    if (!player.getHand().isBlackjack()) {
        while (!player.getHand().isBust()) {
            std::cout << "Select an action: (H)it or (S)tand" << std::endl;
            char action;
            std::cin >> action;
            if (action == 'H' || action == 'h') {
                player.addCard(deck.dealCard());
                std::cout << player.getHand().toString() << std::endl;

            }
            else if (action == 'S' || action == 's') {
                std::cout << "Player Stands" << std::endl;
                break;
            }
            else {
                std::cout << "Invalid action" << std::endl;
            }


        }
    }


}

void Game::dealerTurn() {
    if (!dealer.getHand().isBlackjack()) {

        while (!dealer.getHand().isBust()) {
            if (dealer.getHand().getBestTotal() == 17) {
                std::cout << "Dealer Stands" << std::endl;
                break;
            }
            dealer.addCard(deck.dealCard());
            std::cout << dealer.getHand().toString() << std::endl;

         }
    }

}

void Game::showHands(bool revealDealer){

    std::cout << "Player Hand: " << player.getHand().toString() << std::endl;

    if (revealDealer) {
        std::cout << "Dealer Hand: " << dealer.getHand().toString() << std::endl;

    }
    else {
        std::cout << "Dealer Hand: " << dealer.getHand().hiddenToString() << std::endl;

    }
}



void Game::determineResult() {
    if (player.getHand().getBestTotal() > dealer.getHand().getBestTotal()) {
       std::cout << "Player Wins" << std::endl;
    }
    else if (player.getHand().getBestTotal() < dealer.getHand().getBestTotal()) {
        std::cout << "The House always wins" << std::endl;
    }
    else {
        std::cout << "Draw??" << std::endl;
    }
}



void Game::run() {
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


}




