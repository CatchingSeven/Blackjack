#include <iostream>
#include "Card.h"
#include "Deck.h"

int main() {
    Deck d;
    d.print();
    std::cout <<" " << std::endl;
    d.shuffle();
    d.print();


    return 0;
}