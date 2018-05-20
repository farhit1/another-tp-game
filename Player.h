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

class Game;

class Player {
public:
    const std::string name;
    int money;

    WarEntity war;
    EconomicEntity economy;

    Game* game;

    Player() = delete;
    Player(std::string name, Game* game);

    bool isDead() const;

    virtual Token get() const = 0;

    virtual void print(std::string message) const = 0;

    void makeMove();

    void addUnit(UnitClass* newUnitClass, std::string unitClass, std::string newUnitName) {
        Squad* unitsSquad = nullptr;
        for (Squad& squad: war._squads)
            if (squad._name == unitClass)
                unitsSquad = &squad;
        if (!unitsSquad)
            throw Execute::Exception("no such squad in your army");

        if (money < newUnitClass->cost)
            throw Execute::Exception("not enough money");
        unitsSquad->addUnit(newUnitClass, newUnitName);

        money -= newUnitClass->cost;
    }

    void addFactor(FactorClass* factorClass) {
        if (money < factorClass->cost)
            throw Execute::Exception("not enough money");
        economy.addFactor(factorClass);

        money -= factorClass->cost;
    }

    ~Player() = default;
};

#endif //TP2_PLAYER_H
