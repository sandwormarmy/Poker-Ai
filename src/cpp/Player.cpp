//
// Created by steff on 15/02/2025.
//

#include "../header/Player.h"

Player::Player(std::string name, unsigned int balance) {
    this->name = name;
    this->balance = balance;
    isBigBlind = false;
    isSmallBlind = false;
}

std::string Player::getName() {
    return name;
}

std::vector<Card> Player::getHand() {
    return hand;
}

unsigned int Player::getBalance() {
    return balance;
}

void Player::setBalance(unsigned int val) {
    balance = val;
}

void Player::dealHand(std::vector<Card> val) {
    this->hand = val;
}
