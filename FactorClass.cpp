//
// Created by Fargat on 24/04/2018.
//

#include "FactorClass.h"

FactorClass::FactorClass(std::string&& name, int cost, int bonus) :
        name(std::move(name)),
        cost(cost),
        bonus(bonus) {}

std::string FactorClass::info() const {
    return pprint(
            std::make_pair("Name", name),
            std::make_pair("Cost", cost),
            std::make_pair("Daily bonus", bonus)
    );
}