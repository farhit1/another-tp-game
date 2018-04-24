//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_PLAYER_H
#define TP2_PLAYER_H


#include <string>
#include "Time.h"
#include "Token.h"
#include "WarEntity.h"
#include "EconomicEntity.h"
#include "Move.h"
#include "Execute.h"

class Player {
public:
    std::string name;

    WarEntity war;
    EconomicEntity economy;

    Player() = delete;
    explicit Player(const std::string& name);

    bool isDead() const;

    virtual Token get() const = 0;

    virtual void print(std::string&& message) const = 0;

    void makeMove();

    ~Player() = default;
};

#endif //TP2_PLAYER_H
