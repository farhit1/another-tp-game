//
// Created by Fargat on 24/04/2018.
//

#include "Unit.h"

Unit::Unit(UnitClass* unitClass, std::string name) :
        _unitClass(unitClass),
        _name(name) {
    _health = unitClass->health;
}

std::string Unit::info() const {
    return pprint(
            std::make_pair("Name", _name),
            std::make_pair("Health", _health)
    ) + "Unit class info:\n" + _unitClass->info();
}

bool Unit::alive() const {
    return _health > 0;
}

void Unit::attack(Unit& other) {
    other._health = std::max(0, other._health - _unitClass->attack);
    _health = std::max(0, _health - other._unitClass->defence);
}