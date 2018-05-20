//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_CONSOLEPLAYER_H
#define TP2_CONSOLEPLAYER_H

#include "Player.h"
#include <iostream>
#include <string>

class ConsolePlayer : public Player {
    using Player::Player;

    Token get() const override;

    void print(std::string message) const override;
};

#endif //TP2_CONSOLEPLAYER_H
