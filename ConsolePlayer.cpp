//
// Created by Fargat on 24/04/2018.
//

#include "ConsolePlayer.h"

Token ConsolePlayer::get() const {
    std::string s;
    std::cout << this->name << " >> ";
    std::cin >> s;
    return Token(const_cast<ConsolePlayer*>(this), s);
}

void ConsolePlayer::print(std::string&& message) const {
    std::cout << this->name << ", " << message << std::endl;
}