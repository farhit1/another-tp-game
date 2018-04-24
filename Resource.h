//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_RESOURCE_H
#define TP2_RESOURCE_H

#include <vector>
#include "UnitClass.h"
#include "FactorClass.h"
#include "DataTree.h"

class Resource {
    Resource() = default;

    static std::vector<UnitClass> availableUnits;
    static std::vector<FactorClass> availableFactors;

public:
    static void get();
};

#endif //TP2_RESOURCE_H
