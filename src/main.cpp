#include <iostream>
#include "../include/Card.h"
#include "../include/Deck.h"

int main() {
    Deck d;
    /*d.print();
    std::cout <<" " << std::endl;
    d.shuffle();
    d.print();
    std::cout <<" " << std::endl;
    d.shuffle();
    Card a = d.dealCard();
    Card b = d.dealCard();
    std::cout << a.getName() << std::endl;
    std::cout << b.getName() << std::endl;


    d.shuffle();

    std::cout <<" " << std::endl;

    Card c = d.dealCard();
    Card e = d.dealCard();
    std::cout << c.getName() << std::endl;
    std::cout << e.getName() << std::endl; */



    std::cout << d.isEmpty();




    return 0;
}