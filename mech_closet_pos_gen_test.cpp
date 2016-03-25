#include <iostream>
#include <stdint.h>

constexpr uint8_t numCarts = 3;
constexpr uint8_t n = 3 + 2 * (numCarts-1) - 1; // dont use this in the real thing, just for printing

long* targetPosGenerator(uint8_t N)
{

    const uint8_t n = 3 + 2 * (N-1) - 1; // number of positions
    long* targetPos = new long[n];

    const long x = 10;
    const long d = 100;

    for(uint8_t i = 0; i < N-1; ++i)
        targetPos[i] = x * (i+1);

    for(uint8_t i = n - (N-1); i < n; ++i)
        targetPos[i] = x * (i-1) + (2*d);

    targetPos[N-1] = (N-1) * x + d;
    targetPos[N] = targetPos[N-1] + d;

    return targetPos;

}

void reverseDirection(long* targetPos, uint8_t N)
{

    const uint8_t n = 3 + 2 * (N-1) - 1; // number of positions

    for(uint8_t i = 0; i < n/2; ++i)
    {

        long temp = -1 * targetPos[i];
        targetPos[i] = -1 * targetPos[(n - 1) - i];
        targetPos[(n - 1) - i] = temp;

    }

}

long* targetPositions = targetPosGenerator(numCarts);

int main()
{

    for(uint8_t i = 0; i < n; ++i)
        std::cout << targetPositions[i] << " ";

    std::cout << std::endl;

    reverseDirection(targetPositions, numCarts);

    for(uint8_t i = 0; i < n; ++i)
        std::cout << targetPositions[i] << " ";    

    std::cout << std::endl;

    reverseDirection(targetPositions, numCarts);

    for(uint8_t i = 0; i < n; ++i)
        std::cout << targetPositions[i] << " ";    

    std::cout << std::endl;

    reverseDirection(targetPositions, numCarts);

    for(uint8_t i = 0; i < n; ++i)
        std::cout << targetPositions[i] << " ";    

    std::cout << std::endl;

    return 0;

}
