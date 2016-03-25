#include "Wheel.h"
#include "Stepper.h"
#include <Arduino.h>
#include "RotationalMotion.h"

Wheel::Wheel()
    : radius(0), stepper(NULL), targetPos(0)
{}

Wheel::Wheel(double r, Stepper* stepper)
    : radius(r), stepper(stepper), targetPos(0)
{}

void Wheel::setStepDelay(unsigned long delay) {

    stepper->setStepDelay(delay);

}

void Wheel::setTargetPos(long xf) {

    using RotationalMotion::distanceToRevs;

    // Old targetPos is the starting position
    stepper->setRotations(distanceToRevs(xf - targetPos, radius));
    targetPos = xf;

}

void Wheel::setTargetDispl(long dx) {

    using RotationalMotion::distanceToRevs;

    stepper->setRotations(distanceToRevs(dx, radius));
    targetPos = dx;

}

long Wheel::getTargetPos() {

    return targetPos;

}

long Wheel::getCurrentPos() {

    using RotationalMotion::revsToDistance;

    return targetPos - revsToDistance(stepper->getRevsLeft(), radius);

}

long Wheel::distanceLeft() {

    using RotationalMotion::revsToDistance;

    return revsToDistance(stepper->getRevsLeft(), radius);

}

bool Wheel::stepTowardsTarget() {

    return stepper->step();

}

bool Wheel::reachedTarget() {

    return stepper->getStepsLeft() == 0;

}

void Wheel::stop() {

    targetPos = getCurrentPos();
    stepper->setSteps(0);

}

void Wheel::resetOrigin() {

    targetPos = 0;
    stepper->setSteps(0);

}

void Wheel::move(long displacement) {

    setTargetDispl(displacement);
    while (!reachedTarget())
        stepTowardsTarget();
    targetPos = 0;

}

void Wheel::moveTo(long position) {

    setTargetPos(position);
    while (!reachedTarget())
        stepTowardsTarget();

}
