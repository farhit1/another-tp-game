//
// Created by Fargat on 21/04/2018.
//

#ifndef TP2_DATATREE_H
#define TP2_DATATREE_H

#include <vector>
#include <string>


struct DataTree {
    typedef std::pair<std::string, std::string> property;

    struct Node {
        std::vector<property> properties;
        std::vector<Node> children;
        std::string name;

        bool isLeaf() const;

        std::string find(std::string s) const;
    };

    Node root;
};

enum class Extension {
    XML
};

template<Extension = Extension::XML>
DataTree GetTree(const char *filename);

template<Extension = Extension::XML>
DataTree PrintTree(const char *filename);

#endif //TP2_DATATREE_H
