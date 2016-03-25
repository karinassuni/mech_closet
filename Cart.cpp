#include "Cart.h"
#include "Wheel.h"
#include <Arduino.h>

Cart::Cart()
    : rightWheel(NULL), leftWheel(NULL)
{}

Cart::Cart(Wheel* wR, Wheel* wL)
    : rightWheel(wR), leftWheel(wL)
{}

void Cart::setStepDelay(unsigned long delay) {

    rightWheel->setStepDelay(delay);
    leftWheel->setStepDelay(delay);

}

void Cart::setTargetPos(long xf) {

    rightWheel->setTargetPos(xf);
    leftWheel->setTargetPos(-xf);

}

void Cart::setTargetDispl(long dx) {

    rightWheel->setTargetDispl(dx);
    leftWheel->setTargetDispl(-dx);

}

long Cart::getTargetPos() {

    return rightWheel->getTargetPos();

}

long Cart::getCurrentPos() {

    return rightWheel->getCurrentPos();

}

long Cart::distanceLeft() {

    return rightWheel->distanceLeft();

}

void Cart::stepTowardsTarget() {

    rightWheel->stepTowardsTarget();
    leftWheel->stepTowardsTarget();

}

bool Cart::reachedTarget() {

    return leftWheel->reachedTarget();

}

void Cart::stop() {

    rightWheel->stop();
    leftWheel->stop();

}

void Cart::resetOrigin() {

    rightWheel->resetOrigin();
    leftWheel->resetOrigin();

}

void Cart::move(long displacement) {

    setTargetDispl(displacement);
    while (!reachedTarget()) 
        stepTowardsTarget();
    resetOrigin();

}

void Cart::moveTo(long position) {

    setTargetPos(position);
    while (!reachedTarget())
        stepTowardsTarget();

}

