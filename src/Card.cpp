//
// Created by maxhe on 11/13/2025.
//

#include "../include/Card.h"

/* helper to map enum ranks to a string */
std::map<Suit, std::string> SuitToString = {
  {Suit::Clubs, "Clubs"},
{Suit::Diamonds, "Diamonds"},
{Suit::Hearts, "Hearts"},
{Suit::Spades, "Spades"},



};
std::map<Rank, std::string> RankToString = { // legacy, not used kept in case need for debuffinf purposes
  {Rank::Two, "Two"},
{Rank::Three, "Three"},
{Rank::Four, "Four"},
{Rank::Five, "Five"},
{Rank::Six, "Six"},
{Rank::Seven, "Seven"},
{Rank::Eight, "Eight"},
{Rank::Nine, "Nine"},
{Rank::Ten, "Ten"},
{Rank::Jack, "Jack"},
{Rank::Queen, "Queen"},
{Rank::King, "King"},
{Rank::Ace, "Ace"},






};

Card::Card(Suit suit, Rank rank){
    this->suit = suit;
    this->rank = rank;


      this->name = RankToString[rank] + " of " + SuitToString[suit];


}

int Card::getValue() const {
  switch (this->rank){
    case Rank::Jack:
    case Rank::Queen:
    case Rank::King:
      return 10;
    case Rank::Ace:
      return 11;
    default:
      return (int)this->rank;


  }
}








Rank Card::getRank() const {
  return rank;
}

Suit Card::getSuit() const {
  return suit;
}


std::string Card::getName() const{

  return name;
}




