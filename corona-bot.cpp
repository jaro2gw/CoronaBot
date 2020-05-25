/*  Project by 
  Hercog Maciej,
  Jaroński Piotr, 
    Kolanowski Jan, 
  Mieczyński Paweł, 
    Szalczyk Paweł
*/

//instrukcja obsługi switcha na dole

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

    const int ENSURE_STOP = 1;
}

namespace Motor {
    struct motor {
        int activate;
        int forward;
        int backward;
    };

    struct motor left = {
            Constant::MOTOR_LEFT_ACTIVATE,
            Constant::MOTOR_LEFT_FORWARD,
            Constant::MOTOR_LEFT_BACKWARD
    };

    struct motor right = {
            Constant::MOTOR_RIGHT_ACTIVATE,
            Constant::MOTOR_RIGHT_FORWARD,
            Constant::MOTOR_RIGHT_BACKWARD
    };

    void activate(struct motor *m) {
        pinMode(m->activate, OUTPUT);
        pinMode(m->forward, OUTPUT);
        pinMode(m->backward, OUTPUT);

        digitalWrite(m->activate, HIGH);
    }

    void forward(struct motor *m) {
        digitalWrite(m->forward, HIGH);
        digitalWrite(m->backward, LOW);
    }

    void backward(struct motor *m) {
        digitalWrite(m->forward, LOW);
        digitalWrite(m->backward, HIGH);
    }

    void stop(struct motor *m) {
        digitalWrite(m->forward, LOW);
        digitalWrite(m->backward, LOW);
    }
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

void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);

    Motor::activate(&Motor::left);
    Motor::activate(&Motor::right);

    Sensor::activate(&Sensor::left);
    Sensor::activate(&Sensor::right);

    Serial.println("1 na czujniku to bialy, 0 to czarny.");
}

int stop = Constant::ENSURE_STOP;

void loop() {
    digitalWrite(13, LOW);
    int leftNear = Sensor::near(&Sensor::left);
    int rightNear = Sensor::near(&Sensor::right);

    if (leftNear == LOW && rightNear == LOW) {
        Serial.println("Forward!");

        forward(&Motor::left);
        forward(&Motor::right);

        stop = Constant::ENSURE_STOP;
    }

    if (leftNear == HIGH && rightNear == LOW) {
        Serial.println("Left");

        backward(&Motor::left);
        forward(&Motor::right);

        stop = Constant::ENSURE_STOP;
    }

    if (leftNear == LOW && rightNear == HIGH) {
        Serial.println("Right");

        forward(&Motor::left);
        backward(&Motor::right);

        stop = Constant::ENSURE_STOP;
    }

    if (leftNear == HIGH && rightNear == HIGH) {
        if (--stop) Serial.println("Ensure Stop");
        else {
            stop(&Motor::left);
            stop(&Motor::right);
        }
        delay(400);
    }

    delay(100);
}


/* 

Obsługa switcha:

1 - lewy silnik - bliski czujnik - gdy aktywny pojazd jedzie w lewo
2 - lewy silnik - daleki czujnik - póki co bez funkcjonalności
3 - prawy silnik - bliski czujnik - gdy aktywny pojazd jedzie w prawo
4 - prawy silnik - daleki czujnik - póki co bez funkcjonalności
1 i 3 - gdy razem aktywne pojazd jedzie na wprost
Gdy żaden nieaktywny pojazd się nie porusza

*/