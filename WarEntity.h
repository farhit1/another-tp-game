//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_WARENTITY_H
#define TP2_WARENTITY_H

#include "Squad.h"
#include <vector>
#include <algorithm>

// war entity
class WarEntity {
public:
    std::vector<Squad> _squads;

    WarEntity() = default;
    ~WarEntity() = default;

    bool alive() const;

    void addSquad(std::string name);

    bool findSquad(const std::string& name) const;

    std::string info() const;
};

#endif //TP2_WARENTITY_H
