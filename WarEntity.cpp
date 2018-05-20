//
// Created by Fargat on 24/04/2018.
//

#include "WarEntity.h"

bool WarEntity::alive() const {
    return !_squads.empty();
}

void WarEntity::addSquad(std::string name) {
    _squads.emplace_back(name);
}

bool WarEntity::findSquad(const std::string& name) const {
    for (const Squad& squad : _squads)
        if (squad._name == name)
            return true;
    return false;
}

std::string WarEntity::info() const {
    std::string info;
    if (_squads.empty())
        info = "you have no squads";
    else {
        info = "your squads:\n";
        for (const Squad &squad : _squads)
            info += squad.info();
        info.pop_back();
    }
    return info;
}