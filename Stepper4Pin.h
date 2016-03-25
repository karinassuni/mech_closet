#ifndef Stepper4Pin_h
#define Stepper4Pin_h

#include <Arduino.h>
#include "Stepper.h"

class Stepper4Pin : public Stepper {

    private:

        uint8_t pin1, pin2, pin3, pin4;
        int8_t stepSequence; // used by doStep()

        void doStep();

    public:

        Stepper4Pin(long stepsPerRev, uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4, unsigned long delay=1000);

}; // class Stepper4Pin

#endif

