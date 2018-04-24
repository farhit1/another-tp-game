//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_EXECUTE_H
#define TP2_EXECUTE_H

#include "Move.h"
#include <vector>

class Execute {
public:
    Execute() = default;

    static std::vector<Move*> availableMoves;

    struct MoveAdder {
        MoveAdder() = delete;
        explicit MoveAdder(Move* move);
    };

    static Move::Signal execute(Token&& token);
};


#endif //TP2_EXECUTE_H
