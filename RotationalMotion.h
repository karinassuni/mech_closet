#ifndef RotationalMotion_h
#define RotationalMotion_h

namespace RotationalMotion {

    double distanceToRevs(long distance, double radius);
    long revsToDistance(double revs, double radius);

    long revsToSteps(double revs, long stepsPerRev);
    double stepsToRev(long steps, long stepsPerRev);

    long stepsToDistance(long steps, long stepsPerRev, double radius);
    long distanceToSteps(long distance, long stepsPerRev, double radius);

}

#endif
