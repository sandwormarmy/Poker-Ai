//
// Created by steff on 14/02/2025.
//
#include "CardUtils.h"

std::string rankToString(const Rank rank) {
    switch (rank) {
        case Rank::TWO:   return "2";
        case Rank::THREE: return "3";
        case Rank::FOUR:  return "4";
        case Rank::FIVE:  return "5";
        case Rank::SIX:   return "6";
        case Rank::SEVEN: return "7";
        case Rank::EIGHT: return "8";
        case Rank::NINE:  return "9";
        case Rank::TEN:   return "10";
        case Rank::JACK:  return "Jack";
        case Rank::QUEEN: return "Queen";
        case Rank::KING:  return "King";
        case Rank::ACE:   return "Ace";
        default:          return "Unknown";
    }
}

std::string suitToString(const Suit suit) {
    switch (suit) {
        case Suit::CLUBS:    return "Clubs";
        case Suit::DIAMONDS: return "Diamonds";
        case Suit::HEARTS:   return "Hearts";
        case Suit::SPADES:   return "Spades";
        default:             return "Unknown";
    }
}


std::ostream& operator<<(std::ostream& os, const Rank rank) {
    return os << rankToString(rank);
}

std::ostream& operator<<(std::ostream& os, const Suit suit) {
    return os << suitToString(suit);
}