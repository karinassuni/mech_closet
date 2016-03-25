#ifndef Stepper_h
#define Stepper_h

class Stepper {

    protected:

        const long stepsPerRev;
        unsigned long stepDelay; // in microseconds
        unsigned long lastStepTime; // used by step()
        long stepsLeft; // effectively always positive
        bool clockwise;

        virtual void doStep() = 0;

    public:

        Stepper(long stepsPerRev, unsigned long delay=1000);

        void setSteps(long steps);

        void setRotations(double rotations);

        long getStepsLeft();

        double getRevsLeft();

        void setStepDelay(unsigned long delay);

        bool step();

}; // class Stepper

#endif

