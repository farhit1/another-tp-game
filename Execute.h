//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_EXECUTE_H
#define TP2_EXECUTE_H

#include "Move.h"
#include <vector>
#include <exception>

class Execute {
public:
    struct Exception : std::exception {
        std::string info;
        explicit Exception(std::string info);
    };

    static std::vector<std::unique_ptr<Move>> availableMoves;

    struct MoveAdder {
        MoveAdder() = delete;
        explicit MoveAdder(std::unique_ptr<Move> move);
    };

    static Move::result execute(const Token& token);
};


#endif //TP2_EXECUTE_H
