//
// Created by Fargat on 24/04/2018.
//

#include "EconomicEntity.h"

int EconomicEntity::getBonus() const {
    int totalBonus = 0;
    for (const Factor& factor : _factors)
        totalBonus += factor.getBonus();
    return totalBonus;
}

void EconomicEntity::addFactor(const Factor& factorClass) {
    _factors.emplace_back(factorClass);
}

