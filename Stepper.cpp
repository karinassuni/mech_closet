#include "Stepper.h"
#include <Arduino.h>

Stepper::Stepper(long stepsPerRev, unsigned long delay)
    : stepsPerRev(stepsPerRev), stepDelay(delay), lastStepTime(0),
    stepsLeft(0), clockwise(true)
{}

void Stepper::setSteps(long steps) {

    if (steps < 0) {
        clockwise = false;
        steps *= -1;
    }
    else
        clockwise = true;

    stepsLeft = steps;

}

void Stepper::setRotations(double rotations) {

    setSteps((long) (rotations * stepsPerRev));

}

long Stepper::getStepsLeft() {

    return stepsLeft * (clockwise == false ? -1 : 1);

}

double Stepper::getRevsLeft() {

    return ((double) stepsLeft) / stepsPerRev * (clockwise == false ? -1 : 1);

}

void Stepper::setStepDelay(unsigned long delay) {

    stepDelay = delay;

}

bool Stepper::step() {

    unsigned long currentTime = micros();

    if (stepsLeft > 0 && currentTime - lastStepTime > stepDelay) {
        doStep();
        --stepsLeft;
        lastStepTime = currentTime;
        return true;
    }

    return false;

}

