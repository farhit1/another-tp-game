//
// Created by Fargat on 21/04/2018.
//

#ifndef TP2_XMLHANDLER_H
#define TP2_XMLHANDLER_H

#include <fstream>
#include "DataTree.h"

namespace {
    void add(DataTree::Node* node, const std::string& s, size_t&& l) {
        while (l != s.length() && s[l] != '<')
            ++l;
        if (l == s.length())
            return;
        ++l;
        while (s[l] != '>')
            node->name += s[l++];
        ++l;
        //while ()
    }
}


template<>
DataTree GetTree<0>(const char* filename) {
    std::ifstream file(filename);
    std::string text;
    std::string s;
    while (getline(file, s))
        s += text;

    DataTree dataTree;
    add(&dataTree.root, text, 0);

    return dataTree;
}

template<>
DataTree PrintTree<0>(const char* filename) {

}


#endif //TP2_XMLHANDLER_H
