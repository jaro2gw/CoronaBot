/* Project by:
 * Hercog Maciej,
 * Jaroński Piotr,
 * Kolanowski Jan,
 * Mieczyński Paweł,
 * Szalczyk Paweł
 */

#include "Motor.hpp"
#include "Sensor.hpp"
#include "speed.hpp"

void setup() {
    Serial.begin(9600);

    Motor::LEFT->activate();
    Motor::RIGHT->activate();

    Sensor::LEFT->activate();
    Sensor::RIGHT->activate();

    Speed::activate();

    Serial.println("Sensor input 0 => black color detected.")
    Serial.println("Sensor input 1 => white color detected.")
}

void loop() {
    int leftNear = Sensor::LEFT->near();
    int rightNear = Sensor::RIGHT->near();

    if (leftNear xor rightNear) {

//        if (leftNear == LOW) {
        if (leftNear == HIGH) {
            Serial.println("Left");

            Motor::LEFT->stop();
            Motor::RIGHT->forward();
        }

//        if (rightNear == LOW) {
        if (rightNear == HIGH) {
            Serial.println("Right");

            Motor::LEFT->forward();
            Motor::RIGHT->stop();
        }

        Speed::decrease();
    } else {
        Serial.println("Forward!");

        Motor::LEFT->forward();
        Motor::RIGHT->forward();

        Speed::increase();
    }

    delay(100);
}
