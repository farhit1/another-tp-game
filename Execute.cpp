//
// Created by Fargat on 24/04/2018.
//

#include "Execute.h"

std::vector<std::unique_ptr<Move>> Execute::availableMoves = {};

Execute::MoveAdder::MoveAdder(std::unique_ptr<Move> move) {
    availableMoves.push_back(std::move(move));
}

Move::result Execute::execute(const Token& token) {
    for (const auto& move : availableMoves)
        if (move->parse(token)) {
            std::string message = "";
            Move::Signal signal = move->signal();
            try {
                move->execute(token);
            }
            catch (Exception& exc) {
                std::swap(exc.info, message);
                signal = Move::Signal::exec_failed;
            };
            return std::make_pair(signal, std::move(message));
        }
    return std::make_pair(Move::Signal::not_found, "");
}
