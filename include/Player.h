//
// Created by maxhe on 11/13/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"


class Player {
    private:
      Hand hand;
    public:
      void clearHand();
      void addCard(const Card& card);
      Hand& getHand();


};



#endif //PLAYER_H
