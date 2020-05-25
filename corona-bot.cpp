/* Project by:
 * Hercog Maciej,
 * Jaroński Piotr,
 * Kolanowski Jan,
 * Mieczyński Paweł,
 * Szalczyk Paweł
 */


namespace Motor {

}

namespace Sensor {
    struct sensor {
        int near;
        int far;
    };

    struct sensor left = {
            Constant::SENSOR_LEFT_NEAR,
            Constant::SENSOR_LEFT_FAR
    };

    struct sensor right = {
            Constant::SENSOR_RIGHT_NEAR,
            Constant::SENSOR_RIGHT_FAR
    };

    void activate(struct sensor *s) {
        pinMode(s->near, INPUT);
        pinMode(s->far, INPUT);
    }

    int near(struct sensor *s) { return digitalRead(s->near); }

    int far(struct sensor *s) { return digitalRead(s->far); }
}

namespace Speed {
    void activate() {
        pinMode(SPEED_LEVEL_CONTROLLER, OUTPUT);
    }

    void increase() {
        digitalWrite(Constant::SPEED_LEVEL_CONTROLLER, LOW);
    }

    void decrease() {
        digitalWrite(Constant::SPEED_LEVEL_CONTROLLER, HIGH);
    }
}

void setup() {
    Serial.begin(9600);

    Motor::activate(&Motor::left);
    Motor::activate(&Motor::right);

    Sensor::activate(&Sensor::left);
    Sensor::activate(&Sensor::right);

    Speed::activate();

    Serial.println("1 na czujniku to bialy, 0 to czarny.");
}

void loop() {
    int leftNear = Sensor::near(&Sensor::left);
    int rightNear = Sensor::near(&Sensor::right);

    if (leftNear xor rightNear) {
        if (leftNear) {
            Serial.println("Left");

            backward(&Motor::left);
            forward(&Motor::right);
        }

        if (rightNear) {
            Serial.println("Right");

            forward(&Motor::left);
            backward(&Motor::right);
        }

        Speed::decrease();
    } else {
        Serial.println("Forward!");

        forward(&Motor::left);
        forward(&Motor::right);

        Speed::increase();
    }

    delay(100);
}
