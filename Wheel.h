#ifndef Wheel_h
#define Wheel_h

class Stepper;

class Wheel {

    private:

        Stepper* stepper;
        const double radius;
        long targetPos;

    public:

        Wheel();
        Wheel(double r, Stepper* stepper);

        void setStepDelay(unsigned long delay);

        void setTargetPos(long xf);

        void setTargetDispl(long dx);

        long getTargetPos();

        long getCurrentPos();

        long distanceLeft();

        bool stepTowardsTarget();

        bool reachedTarget();

        void stop();

        void resetOrigin(); 

        void move(long displacement); 

        void moveTo(long position); 

}; // class Wheel

#endif

