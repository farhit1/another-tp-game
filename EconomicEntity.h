//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_ECONOMYENTITY_H
#define TP2_ECONOMYENTITY_H

#include <vector>
#include "Factor.h"

// economic entity
class EconomicEntity {
    std::vector<Factor> _factors;

public:
    EconomicEntity() = default;
    ~EconomicEntity() = default;

    int getBonus() const;

    void addFactor(const Factor& factorClass);
};



#endif //TP2_ECONOMYENTITY_H
