//
// Created by Fargat on 24/04/2018.
//

#include "Execute.h"

std::vector<Move*> Execute::availableMoves = {};

Execute::MoveAdder::MoveAdder(Move* move) {
    availableMoves.push_back(move);
}

Move::Signal Execute::execute(Token&& token) {
    for (auto& move : availableMoves)
        if (move->parse(token)) {
            move->execute(token);
            return move->signal;
        }
    return Move::Signal::fail;
}
