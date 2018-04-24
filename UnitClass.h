//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_UNITCLASS_H
#define TP2_UNITCLASS_H

#include <string>
#include "propertyPrinter.h"

class UnitClass {
public:
    const std::string name;
    const int cost;
    const int health;
    const int attack;
    const int defence;

    UnitClass(std::string&& name, int cost, int health, int attack, int defence);

    std::string info() const;

    ~UnitClass() = default;
};


#endif //TP2_UNITCLASS_H
