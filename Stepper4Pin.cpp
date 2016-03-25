#include "Stepper4Pin.h"
#include "Stepper.h"
#include <Arduino.h>

Stepper4Pin::Stepper4Pin(long stepsPerRev, uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4, unsigned long delay)
    : Stepper(stepsPerRev, delay), pin1(p1), pin2(p2), pin3(p3), pin4(p4), stepSequence(0)
{

    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);

}

void Stepper4Pin::doStep() {

    switch (stepSequence) {

        case 0:
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, LOW);
            digitalWrite(pin3, LOW);
            digitalWrite(pin4, HIGH);
            break;
        case 1:
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, LOW);
            digitalWrite(pin3, HIGH);
            digitalWrite(pin4, HIGH);
            break;
        case 2:
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, LOW);
            digitalWrite(pin3, HIGH);
            digitalWrite(pin4, LOW);
            break;
        case 3:
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, HIGH);
            digitalWrite(pin3, HIGH);
            digitalWrite(pin4, LOW);
            break;
        case 4:
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, HIGH);
            digitalWrite(pin3, LOW);
            digitalWrite(pin4, LOW);
            break;
        case 5:
            digitalWrite(pin1, HIGH);
            digitalWrite(pin2, HIGH);
            digitalWrite(pin3, LOW);
            digitalWrite(pin4, LOW);
            break;
        case 6:
            digitalWrite(pin1, HIGH);
            digitalWrite(pin2, LOW);
            digitalWrite(pin3, LOW);
            digitalWrite(pin4, LOW);
            break;
        case 7:
            digitalWrite(pin1, HIGH);
            digitalWrite(pin2, LOW);
            digitalWrite(pin3, LOW);
            digitalWrite(pin4, HIGH);
            break;
        case 8:
            stepSequence = 0;
            break;
        case -1:
            stepSequence = 7;
            break;
        default:
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, LOW);
            digitalWrite(pin3, LOW);
            digitalWrite(pin4, LOW);
            break;

    } // switch (stepSequence)

    if (clockwise) { ++stepSequence; }
    else { --stepSequence; }

} // void doStep
