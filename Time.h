//
// Created by Fargat on 24/04/2018.
//

#ifndef TP2_TIME_H
#define TP2_TIME_H

class Time {
    static int _day;

public:
    Time() = delete;

    static int getDay();

    static void nextDay();
};

#endif //TP2_TIME_H
