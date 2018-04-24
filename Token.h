//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_TOKEN_H
#define TP2_TOKEN_H


#include <vector>
#include <string>


class Player;

class Token {
    static const char* _delimeters;
    std::vector<std::string> _tokens;

public:
    Player* owner;

    Token() = delete;
    explicit Token(Player* owner, std::string& tokenize);

    size_t size() const;

    size_t find(std::string&& word) const;

    bool isNumber(size_t pos) const;

    int toNumber(size_t pos) const;

    std::string operator[](size_t pos) const;

    ~Token() = default;
};


#endif //TP2_TOKEN_H
