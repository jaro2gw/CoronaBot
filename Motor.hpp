#ifndef CORONABOT_MOTOR_H
#define CORONABOT_MOTOR_H

#include "pin.hpp"

class Motor {
private:
    int _activate;
    int _forward;
    int _backward;

public:
    Motor(int activate, int forward, int backward) {
        pinMode(activate, OUTPUT);
        pinMode(forward, OUTPUT);
        pinMode(backward, OUTPUT);

        this->_activate = activate;
        this->_forward = forward;
        this->_backward = backward;
    }

    void activate() const {
        digitalWrite(_activate, HIGH);
    }

    void forward() const {
        digitalWrite(_forward, HIGH);
        digitalWrite(_backward, LOW);
    }

    void backward() const {
        digitalWrite(_forward, LOW);
        digitalWrite(_backward, HIGH);
    }

    void stop() const {
        digitalWrite(_forward, LOW);
        digitalWrite(_backward, LOW);
    }

    static Motor *LEFT, *RIGHT;
};

Motor *Motor::LEFT = new Motor(
        PIN::MOTOR_LEFT_ACTIVATE,
        PIN::MOTOR_LEFT_FORWARD,
        PIN::MOTOR_LEFT_BACKWARD
);

Motor *Motor::RIGHT = new Motor(
        PIN::MOTOR_RIGHT_ACTIVATE,
        PIN::MOTOR_RIGHT_FORWARD,
        PIN::MOTOR_RIGHT_BACKWARD
);

#endif //CORONABOT_MOTOR_H
