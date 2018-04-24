//
// Created by Fargat on 24/04/2018.
//

#include "Time.h"

int Time::_day = 1;

int Time::getDay() {
    return _day;
}

void Time::nextDay() {
    ++_day;
}