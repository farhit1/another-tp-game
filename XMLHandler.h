//
// Created by Fargat on 21/04/2018.
//

#ifndef TP2_XMLHANDLER_H
#define TP2_XMLHANDLER_H

#include <fstream>
#include <algorithm>
#include "DataTree.h"

class XMLHandlerHelper {
    template<Extension ext>
    friend DataTree GetTree(const char* filename);

    static inline bool isDelimeter(char c);

    static inline void skipDelimeters(const std::string& s, size_t& l);

    static void add(DataTree::Node* node, const std::string& s, size_t& l);
};


template<>
DataTree GetTree<Extension::XML>(const char* filename);

template<>
DataTree PrintTree<Extension::XML>(const char* filename);


#endif //TP2_XMLHANDLER_H
