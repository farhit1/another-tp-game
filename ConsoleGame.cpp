//
// Created by Fargat on 24/04/2018.
//

#include "ConsoleGame.h"
#include "ConsolePlayer.h"

ConsoleGame::ConsoleGame(const std::vector<std::string>& names) :
        Game() {
    for (const std::string& name : names)
        _players.push_back(new ConsolePlayer(name));
}