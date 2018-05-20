//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_FACTORCLASS_H
#define TP2_FACTORCLASS_H

#include <string>
#include "propertyPrinter.h"

class FactorClass {
public:
    const std::string name;
    const int cost;
    const int bonus;

    FactorClass(std::string name, int cost, int bonus);

    std::string info() const;
};

#endif //TP2_FACTORCLASS_H
