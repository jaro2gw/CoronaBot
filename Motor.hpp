//
// Created by pjaro on 25.05.2020.
//

#ifndef CORONABOT_MOTOR_H
#define CORONABOT_MOTOR_H

class Motor {
private:
    int forward;
    int backward;

public:
    Motor(int activate, int forward, int backward) {
        pinMode(activate, OUTPUT);
        pinMode(forward, OUTPUT);
        pinMode(backward, OUTPUT);

        digitalWrite(activate, HIGH);

        this->forward = forward;
        this->backward = backward;
    }

    void forward() {
        digitalWrite(forward, HIGH);
        digitalWrite(backward, LOW);
    }

    void backward() {
        digitalWrite(forward, LOW);
        digitalWrite(backward, HIGH);
    }

    void stop() {
        digitalWrite(forward, LOW);
        digitalWrite(backward, LOW);
    }
};

#endif //CORONABOT_MOTOR_H
