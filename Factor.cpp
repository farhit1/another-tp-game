//
// Created by Fargat on 24/04/2018.
//

#include "Factor.h"

std::string Factor::info() const {
    return "Factor class info:\n" + _factorClass->info();
}

int Factor::getBonus() const {
    return _factorClass->bonus;
}

Factor::Factor(const FactorClass* factorClass) :
        _factorClass(factorClass) {}