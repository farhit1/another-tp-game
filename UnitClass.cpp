//
// Created by Fargat on 24/04/2018.
//

#include "UnitClass.h"

UnitClass::UnitClass(std::string&& name, int cost, int health, int attack, int defence) :
        name(std::move(name)),
        cost(cost),
        health(health),
        attack(attack),
        defence(defence) {}

std::string UnitClass::info() const {
    return pprint(
            std::make_pair("Name", name),
            std::make_pair("Cost", cost),
            std::make_pair("Initial health", health),
            std::make_pair("Attack", attack)
    );
}