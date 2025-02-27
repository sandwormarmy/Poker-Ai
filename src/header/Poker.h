//
// Created by steff on 15/02/2025.
//

#ifndef POKER_H
#define POKER_H
#include <stack>
#include <vector>

#include "Card.h"
#include "Player.h"
#include "../utils/CardUtils.h"

class Poker {
    private:
    std::stack<Card> cardStack;
    std::vector<Player> players;
    unsigned int pot;
    void play();

    public:
    Poker(std::vector<Player> players);

};

#endif //POKER_H
