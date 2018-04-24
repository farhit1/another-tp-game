//
// Created by Fargat on 24/04/2018.
//

#include "Token.h"

const char* Token::_delimeters = " ,.-\n";

Token::Token(Player* owner, std::string& tokenize) :
        owner(owner) {
    char *token = strtok(const_cast<char*>(tokenize.c_str()), _delimeters);
    while (token != nullptr) {
        _tokens.emplace_back(std::string(token));
        token = strtok(nullptr, _delimeters);
    }
}

size_t Token::size() const {
    return _tokens.size();
}

size_t Token::find(std::string&& word) const {
    size_t counter = 0;
    for (const std::string& token : _tokens) {
        if (word == token)
            return counter;
        ++counter;
    }
    return counter;
}

bool Token::isNumber(size_t pos) const {
    if (_tokens[pos].empty())
        return false;
    size_t at = 0;
    if (_tokens[pos][at] == '-')
        ++at;
    while (at < _tokens[pos].length()) {
        if (!isdigit(_tokens[pos][at]))
            return false;
        ++at;
    }
    return true;
}

int Token::toNumber(size_t pos) const {
    return std::stoi(_tokens[pos]);
}

std::string Token::operator[](size_t pos) const {
    return _tokens[pos];
}
