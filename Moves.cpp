//
// Created by Fargat on 24/04/2018.
//

#include "Move.h"
#include "Token.h"
#include "Player.h"

struct NewSquad : Move {
    NewSquad() = default;
    ~NewSquad() = default;

    bool parse(const Token& token) const override {
        if (token.size() != 3)
            return false;
        if (token[0] != "create" && token[1] != "squad")
            return false;
        if (token.owner->war.findSquad(token[2]))
            return false;
        return true;
    }

    void execute(Token& token) override {
        token.owner->war.addSquad(token[2]);
    }

    static const Move::Signal signal = Move::Signal::other;
};
Execute::MoveAdder newSquadMove(new NewSquad());
