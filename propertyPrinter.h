#ifndef TP2_PROPERTYPRINTER_H
#define TP2_PROPERTYPRINTER_H

#include <iostream>
#include <string>

namespace
{
    template<typename T>
    std::string to_string(T t) {
        return std::to_string(t);
    }
    template<>
    std::string to_string<const char*>(const char* t) {
        return std::string(t);
    }
    template<>
    std::string to_string<std::string>(std::string t) {
        return t;
    }

    template<typename ...Args>
    size_t getMargin(size_t maxMargin, Args... args) {
        return maxMargin;
    }
    template<class S, class T, typename ...Args>
    size_t getMargin(size_t maxMargin, std::pair<S, T> property, Args... args) {
        maxMargin = std::max(maxMargin, to_string(property.first).length());
        return getMargin(maxMargin, args...);
    }

    template<typename ...Args>
    void print(std::string &s, size_t margin, Args... args) {}
    template<class S, class T, typename ...Args>
    void print(std::string &s, size_t margin, std::pair<S, T> property, Args... args) {
        // <could be done better>
        std::string pf = to_string(property.first);
        s += pf + ":";
        for (size_t i = 0; i < margin - pf.length() + 1; ++i)
            s += ' ';
        s += to_string(property.second) + '\n';
        // </could be done better>
        print(s, margin, args...);
    }
}

template<typename ...Args>
std::string pprint(Args... args) {
    std::string s;
    print(
            s,
            getMargin(0, args...),
            args...
    );
    return s;
}

#endif //TP2_PROPERTYPRINTER_H
