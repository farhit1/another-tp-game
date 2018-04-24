//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_CONSOLEGAME_H
#define TP2_CONSOLEGAME_H

#include "Game.h"
#include <vector>
#include <string>


class ConsoleGame : public Game {
public:
    explicit ConsoleGame(const std::vector<std::string>& names);
};


#endif //TP2_CONSOLEGAME_H
