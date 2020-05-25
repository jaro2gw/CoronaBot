#ifndef CORONABOT_SPEED_H
#define CORONABOT_SPEED_H

#include "pin.hpp"

namespace Speed {
    void activate() { pinMode(PIN::SPEED_LEVEL, OUTPUT); }
    void increase() { digitalWrite(PIN::SPEED_LEVEL, LOW); }
    void decrease() { digitalWrite(PIN::SPEED_LEVEL, HIGH); }
}

#endif //CORONABOT_SPEED_H
