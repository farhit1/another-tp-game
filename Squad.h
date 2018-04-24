//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_SQUAD_H
#define TP2_SQUAD_H

#include "Unit.h"
#include <string>
#include <vector>

// concrete squad
class Squad {
    std::vector<Unit> _units;

public:
    const std::string _name;

    explicit Squad(std::string&& name);

    std::string info() const;

    bool alive() const;

    void recalc();

    void attack(Squad& other);

    ~Squad() = default;
};


#endif //TP2_SQUAD_H
