//
// Created by Fargat on 24/04/2018.
//

#include "Resource.h"

std::vector<UnitClass> Resource::availableUnits = {};
std::vector<FactorClass> Resource::availableFactors = {};

void Resource::get() {
    DataTree unitsTree = GetTree("units.xml");
    for (const DataTree::Node& unit : unitsTree.root.children) {
        availableUnits.emplace_back(
                unit.find("name"),
                stoi(unit.find("cost")),
                stoi(unit.find("health")),
                stoi(unit.find("attack")),
                stoi(unit.find("defence"))
        );
    }

    DataTree factorsTree = GetTree("factors.xml");
    for (const DataTree::Node& factor : factorsTree.root.children) {
        availableFactors.emplace_back(
                factor.find("name"),
                stoi(factor.find("cost")),
                stoi(factor.find("bonus"))
        );
    }
}