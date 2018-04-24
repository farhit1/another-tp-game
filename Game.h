//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_GAME_H
#define TP2_GAME_H

#include <vector>
#include "Player.h"

class Game {
public:
    std::vector<Player*> _players;

    Game() = default;
    ~Game() = default;

    bool isSomeoneAlive() const;

    void launch();
};


#endif //TP2_GAME_H
