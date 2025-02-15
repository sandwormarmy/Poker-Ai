//
// Created by steff on 15/02/2025.
//

#include "../header/Card.h";

#include <string>


Card::Card(const Rank rank, const Suit suit) {
    this->rank = rank;
    this->suit = suit;
}

Rank Card::getRank() const {
    return rank;
}

Suit Card::getSuit() const {
    return suit;
}

std::string Card::toString() const {
    const char * result = ("" + suitToString(suit) + " " + rankToString(rank)).data();
    return result;
}



