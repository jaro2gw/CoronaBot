//
// Created by pjaro on 25.05.2020.
//

#ifndef CORONABOT_SENSOR_H
#define CORONABOT_SENSOR_H

#include "pin.hpp"

class Sensor {
private:
    int _near;
    int _far;

public:
    Sensor(int near, int far) {
        pinMode(near, INPUT);
        pinMode(far, INPUT);

        this->_near = near;
        this->_far = far;
    }

    int near() const { return digitalRead(_near); }

    int far() const { return digitalRead(_far); }

    static Sensor *LEFT, *RIGHT;
};

Sensor *Sensor::LEFT = new Sensor(
        PIN::SENSOR_LEFT_NEAR,
        PIN::SENSOR_LEFT_FAR
);

Sensor *Sensor::RIGHT = new Sensor(
        PIN::SENSOR_RIGHT_NEAR,
        PIN::SENSOR_RIGHT_FAR
);

#endif //CORONABOT_SENSOR_H