//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_UNIT_H
#define TP2_UNIT_H

#include "UnitClass.h"
#include "propertyPrinter.h"
#include <string>


// concrete unit
class Unit {
    UnitClass* _unitClass;
    std::string _name;

    int _health;

public:
    Unit(UnitClass* unitClass, std::string&& name);

    std::string info() const;

    bool alive() const;

    void attack(Unit& other);

    ~Unit() = default;
};

#endif //TP2_UNIT_H
