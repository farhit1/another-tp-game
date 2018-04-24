//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_MOVE_H
#define TP2_MOVE_H

#include "Token.h"
#include "Resource.h"

struct Move {
    enum class Signal {
        other, start, end, fail
    };

    virtual bool parse(const Token& token) const = 0;
    virtual void execute(Token& token) = 0;
    static const Signal signal = Signal::other;
};

#endif //TP2_MOVE_H
