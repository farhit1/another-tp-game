//
// Created by Fargat on 24/04/2018.
//

#include "Player.h"

Player::Player(std::string name, Game* game) :
        name(name),
        money(Resource::initialMoney),
        game(game) {}

bool Player::isDead() const {
    return Time::getDay() > 2 && !war.alive();
}

void Player::makeMove() {
    if (isDead()) {
        print("you are dead");
        return;
    }
    for (auto& move : Execute::availableMoves)
        if (move->signal() == Move::Signal::start)
            move->execute(Token(this, ""));

    while (true) {
        Move::result result = Execute::execute(get());
        switch (result.first) {
            case Move::Signal::not_found:
                print("no such action");
                break;
            case Move::Signal::exec_failed:
                print("can not perform action: " + result.second);
                break;
            case Move::Signal::end:
                return;
            default:
                break;
        }
        if (isDead()) {
            print("you are dead");
            return;
        }
    }
}