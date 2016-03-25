#include "Stepper4Pin.h"
#include "Wheel.h"
#include "Cart.h"

const uint16_t stepsPerRev = 2048;

Stepper4Pin stepper1R(stepsPerRev, 2, 3, 4, 5);
Stepper4Pin stepper1L(stepsPerRev, 8, 9, 10, 11);
/* Stepper4Pin stepper2R(stepsPerRev, 2, 3, 4, 5); */
/* Stepper4Pin stepper2L(stepsPerRev, 8, 9, 10, 11); */

const double wheelRadius = 10.5; // units unknown

Wheel wheel1R(wheelRadius, &stepper1R);
Wheel wheel1L(wheelRadius, &stepper1L);
/* Wheel wheel2R(wheelRadius, &stepper2R); */
/* Wheel wheel2L(wheelRadius, &stepper2L); */

const uint8_t N = 1; // number of carts

Cart cart1(&wheel1R, &wheel1L);
/* Cart cart2(&wheel2R, &wheel2L); */
Cart carts[N] = {cart1};

const uint8_t n = 3 + 2 * (N-1) - 1; // number of positions

long targetDisplacements[n];

void targetDisplGenerator() {

    const long x = 40; // small distance between carts, units unknown
    const long d = 100; // large distance between positions, units unknown

    for (uint8_t i = 0; i < N-1; ++i)
        targetDisplacements[i] = x;

    for (uint8_t i = n - (N-1); i < n; ++i)
        targetDisplacements[i] = x;

    targetDisplacements[N-1] = targetDisplacements[N] = d;

}

void reverseDirection() {

    for (uint8_t i = 0; i < n/2; ++i) {
        long temp = -1 * targetDisplacements[i];
        targetDisplacements[i] = -1 * targetDisplacements[(n - 1) - i];
        targetDisplacements[(n - 1) - i] = temp;
    }

}

bool allReachedTargets() {

    for (uint8_t i = 0; i < N; i++) {
        if (!carts[i].reachedTarget())
            return false;
    }

    return true;

}

void setup() {

    targetDisplGenerator();

}

void loop() {

    static uint8_t j = 0;
    #define numCarts N

    for (uint8_t i = 0; i < numCarts; ++i, ++j)
        carts[i].setTargetDispl(targetDisplacements[j]);

    while (!allReachedTargets()) {

        for (uint8_t i = 0; i < numCarts; ++i)
            carts[i].stepTowardsTarget();

    }

    delay(1500);

    j -= numCarts - 1;

    if (j > numCarts) {
        j = 0;
        reverseDirection();
    }

}
