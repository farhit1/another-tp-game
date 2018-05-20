//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_MOVE_H
#define TP2_MOVE_H

#include "Token.h"
#include "Resource.h"

struct Move {
    enum class Signal {
        other, start, end, not_found, exec_failed
    };

    typedef std::pair<Signal, std::string> result;

    virtual bool parse(const Token& token) = 0;
    virtual void execute(const Token& token) = 0;
    virtual Move::Signal signal() const = 0;
};

#endif //TP2_MOVE_H
