//
// Created by Fargat on 21/04/2018.
//

#include "DataTree.h"

bool DataTree::Node::isLeaf() const {
    return children.empty();
}

std::string DataTree::Node::find(std::string&& s) const {
    for (auto&& property : properties)
        if (property.first == s)
            return property.second;
    return "";
}