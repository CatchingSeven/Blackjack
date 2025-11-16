#include <iostream>
#include "../include/Card.h"
#include "../include/Deck.h"
#include "../include/Game.h"

int main() {
    bool play = true;

    std::cout << "Welcome to the Blackjack Game!" << std::endl;
    while (play) {
        Game game;
        game.run();
        std::cout <<"Play again? Y/N" <<std::endl;
        char answer;
        std::cin >> answer;
        if (answer == 'N'|| answer == 'n') {
            play = false;
        }
        else if (answer == 'Y' || answer == 'y') {
            std::cout << "Welcome to the Blackjack Game!" << std::endl;
        }

        else {
            std::cout << "Invalid input! Please try again!" << std::endl;
        }

    }





    return 0;
}