//
// Created by steff on 14/02/2025.
//

#ifndef CARD_H
#define CARD_H

#include "../enums/CardUtils.h"
#include <string>

class Card {
    private:
    Rank rank;
    Suit suit;

    public:
    Card(Rank rank, Suit suit);
    ~Card() = default;

    Rank getRank() const;
    Suit getSuit() const;
    std::string toString() const;
};



#endif //CARD_H
