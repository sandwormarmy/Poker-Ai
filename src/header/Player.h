//
// Created by steff on 15/02/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>


#include "Card.h"

class Player {
    private:
    std::string name;
    std::vector<Card> hand;
    unsigned int balance;

    public:
    bool isSmallBlind;
    bool isBigBlind;

    Player(std::string, unsigned int);
    std::string getName();
    std::vector<Card> getHand();
    unsigned int getBalance();

    void setBalance(unsigned int);
    void dealHand(std::vector<Card>);

};
#endif //PLAYER_H
