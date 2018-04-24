//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_FACTOR_H
#define TP2_FACTOR_H

#include "FactorClass.h"
#include <string>


class Factor {
    const FactorClass* _factorClass;

public:
    explicit Factor(const FactorClass* factorClass);

    int getBonus() const;

    std::string info() const;
};


#endif //TP2_FACTOR_H
