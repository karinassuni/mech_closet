#ifndef Cart_h
#define Cart_h

class Wheel;

class Cart {

    private:

        Wheel* rightWheel;
        Wheel* leftWheel;

    public:

        Cart();
        Cart(Wheel* wR, Wheel* wL);

        void setStepDelay(unsigned long delay);

        void setTargetPos(long xf);

        void setTargetDispl(long dx);

        long getTargetPos();

        long getCurrentPos();

        long distanceLeft();

        void stepTowardsTarget();

        bool reachedTarget();

        void stop();

        void resetOrigin(); 

        void move(long displacement); 

        void moveTo(long position); 

}; // class Cart

#endif

