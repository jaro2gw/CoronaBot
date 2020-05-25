//
// Created by pjaro on 25.05.2020.
//

#ifndef CORONABOT_SPEEDCONTROLLER_H
#define CORONABOT_SPEEDCONTROLLER_H

#include "pin.hpp"

namespace Speed {
    void activate() { pinMode(PIN::SPEED_LEVEL, OUTPUT); }
    void increase() { digitalWrite(PIN::SPEED_LEVEL, LOW); }
    void decrease() { digitalWrite(PIN::SPEED_LEVEL, HIGH); }
}

#endif //CORONABOT_SPEEDCONTROLLER_H
