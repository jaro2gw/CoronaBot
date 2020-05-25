//
// Created by pjaro on 25.05.2020.
//

#ifndef CORONABOT_CONSTANT_H
#define CORONABOT_CONSTANT_H

namespace Constant {
        // Left motor
        const int MOTOR_LEFT_ACTIVATE = 2;
        const int MOTOR_LEFT_FORWARD = 3;
        const int MOTOR_LEFT_BACKWARD = 4;

        // Left sensors
        const int SENSOR_LEFT_NEAR = 5;
        const int SENSOR_LEFT_FAR = 6;

        // Right motor
        const int MOTOR_RIGHT_ACTIVATE = 8;
        const int MOTOR_RIGHT_FORWARD = 9;
        const int MOTOR_RIGHT_BACKWARD = 10;

        // Right sensors
        const int SENSOR_RIGHT_NEAR = 11;
        const int SENSOR_RIGHT_FAR = 12;

        const int SPEED_LEVEL_CONTROLLER = 13;
}

#endif //CORONABOT_CONSTANT_H
