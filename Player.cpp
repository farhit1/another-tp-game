//
// Created by Fargat on 24/04/2018.
//

#include "Player.h"

Player::Player(const std::string& name) :
        name(name) {}

bool Player::isDead() const {
    return Time::getDay() > 2 && !war.alive();
}

void Player::makeMove() {
    while (true) {
        if (isDead())
            print("You are dead");
        Move::Signal signal = Execute::execute(get());
        switch (signal) {
            case Move::Signal::fail:
                print("Incorrect move");
                break;
            case Move::Signal::end:
                return;
            default:
                break;
        }
    }
}