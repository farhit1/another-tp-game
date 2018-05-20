//
// Created by Fargat on 21/04/2018.
//

#include "XMLHandler.h"

bool XMLHandlerHelper::isDelimeter(char c) {
    static const std::string delimeters = "\n\t ";
    return std::find(delimeters.begin(), delimeters.end(), c) != delimeters.end();
}

void XMLHandlerHelper::skipDelimeters(const std::string& s, size_t& l) {
    while (l != s.length() && isDelimeter(s[l]))
        ++l;
}

void XMLHandlerHelper::add(DataTree::Node* node, const std::string& s, size_t& l) {
    skipDelimeters(s, l);
    ++l; // expected '<'
    while (!isDelimeter(s[l]) && s[l] != '\\' && s[l] != '>')
        node->name += s[l++];
    // fetch properties
    skipDelimeters(s, l);
    while (s[l] != '>' && s[l] != '/') {
        DataTree::property newProperty;
        while (!isDelimeter(s[l]) && s[l] != '=')
            newProperty.first += s[l++];
        skipDelimeters(s, l);
        if (s[l] == '=') {
            ++l;
            skipDelimeters(s, l);
            switch (s[l]) {
                case '"':
                    ++l;
                    while (s[l] != '"')
                        newProperty.second += s[l++];
                    ++l;
                    break;
                case '\'':
                    ++l;
                    while (s[l] != '\'')
                        newProperty.second += s[l++];
                    ++l;
                    break;
                default:
                    while (!isDelimeter(s[l]))
                        newProperty.second += s[l++];
            }
        }
        node->properties.push_back(std::move(newProperty));
        skipDelimeters(s, l);
    }
    // <tag />
    if (s[l] == '/') {
        ++l; skipDelimeters(s, l); // <tag [/]>
        ++l; skipDelimeters(s, l); // <tag /[>]
        return;
    }

    ++l; skipDelimeters(s, l);
    // while not <tag>...[<]/tag>
    while (s[l + 1] != '/') {
        node->children.emplace_back();
        add(&node->children.back(), s, l);
    }

    // go there <tag>...</tag>[?]...
    while (s[l] != '>')
        ++l;
    ++l; skipDelimeters(s, l);
}

template<>
DataTree GetTree<Extension::XML>(const char* filename) {
    std::ifstream file(filename);
    std::string text;
    std::string s;
    while (getline(file, s))
        text += s;

    DataTree dataTree;
    size_t position = 0;
    XMLHandlerHelper::add(&dataTree.root, text, position);

    return dataTree;
}

template<>
DataTree PrintTree<Extension::XML>(const char* filename) {

}