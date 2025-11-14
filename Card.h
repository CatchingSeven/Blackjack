//
// Created by maxhe on 11/13/2025.
//

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <map>

enum class Suit {Clubs = 0, Diamonds, Hearts, Spades};
enum class Rank {
  Two = 2,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
  Ace
};


extern std::map<Rank, std::string> RankToString;
extern std::map<Suit, std::string> SuitToString;



class Card {
  private:
    Suit suit;
    Rank rank;
    std::string name;

  public:
    Card(Suit suit, Rank rank);

    int getValue() const;
    Rank getRank() const;
    Suit getSuit() const;
    std::string getName() const;



};



#endif //CARD_H
