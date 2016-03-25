#include "RotationalMotion.h"
#include <math.h>

double RotationalMotion::distanceToRevs(long distance, double radius) {

    return ((double) distance) / (2 * M_PI * radius);

}

long RotationalMotion::revsToDistance(double revs, double radius) {

    return (long) (revs * 2 * M_PI * radius);

}

long RotationalMotion::revsToSteps(double revs, long stepsPerRev) {

    return (long) (revs * stepsPerRev);

}

double RotationalMotion::stepsToRev(long steps, long stepsPerRev) {

    return ((double) steps) / stepsPerRev;

}

long RotationalMotion::stepsToDistance(long steps, long stepsPerRev, double radius) {

    return revsToDistance(stepsToRev(steps, stepsPerRev), radius);

}

long RotationalMotion::distanceToSteps(long distance, long stepsPerRev, double radius) {

    return revsToSteps(distanceToRevs(distance, radius), stepsPerRev);

}
