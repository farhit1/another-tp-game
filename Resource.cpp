//
// Created by Fargat on 24/04/2018.
//

#include "Resource.h"

std::vector<UnitClass> Resource::availableUnits = {};
std::vector<FactorClass> Resource::availableFactors = {};

void Resource::get() {
    DataTree unitsTree = GetTree("units.xml");
    for (DataTree::Node unit : unitsTree.root.children) {
        availableUnits.push_back(UnitClass(
                unit.find("name"),
                stoi(unit.find("cost")),
                stoi(unit.find("health")),
                stoi(unit.find("attack")),
                stoi(unit.find("defence"))
        ));
    }

    DataTree factorsTree = GetTree("factors.xml");
    for (DataTree::Node unit : factorsTree.root.children) {
        availableFactors.push_back(FactorClass(
                unit.find("name"),
                stoi(unit.find("cost")),
                stoi(unit.find("bonus"))
        ));
    }
}