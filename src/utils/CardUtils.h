//
// Created by steff on 15/02/2025.
//

#ifndef CARDUTILS_H
#define CARDUTILS_H

#include <string>
#include <iostream>

enum class Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum class Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
                  JACK, QUEEN, KING, ACE };

std::string rankToString(Rank rank);
std::string suitToString(Suit suit);

std::ostream& operator<<(std::ostream& os, Rank rank);
std::ostream& operator<<(std::ostream& os, Suit suit);

#endif //CARDUTILS_H
