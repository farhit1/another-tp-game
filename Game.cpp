//
// Created by Fargat on 24/04/2018.
//

#include "Game.h"

bool Game::isSomeoneAlive() const {
    for (const Player* player : _players)
        if (!player->isDead())
            return true;
    return false;
}

void Game::launch() {
    size_t ord = 0;
    while (isSomeoneAlive()) {
        if (!_players[ord]->isDead()) {
            _players[ord]->makeMove();
            ord = ord + 1;
            if (ord == _players.size()) {
                Time::nextDay();
                ord = 0;
            }
        }
    }
    size_t last = (ord == 0 ? _players.size() - 1 : ord - 1);
    _players[last]->print("You won");
}