#include <iostream>
#include <stdint.h>

constexpr uint8_t numCarts = 1;
constexpr uint8_t n = 3 + 2 * (numCarts-1) - 1; // dont use this in the real thing, just for printing

long* targetDistGenerator(uint8_t N)
{

    const uint8_t n = 3 + 2 * (N-1) - 1; // number of positions
    long* targetDistances = new long[n];

    const long x = 10;
    const long d = 100;

    for(uint8_t i = 0; i < N-1; ++i)
        targetDistances[i] = x;

    for(uint8_t i = n - (N-1); i < n; ++i)
        targetDistances[i] = x;

    targetDistances[N-1] = targetDistances[N] = d;

    return targetDistances;

}

void reverseDirection(long* targetDistances, uint8_t N)
{

    const uint8_t n = 3 + 2 * (N-1) - 1; // number of positions

    for(uint8_t i = 0; i < n/2; ++i)
    {

        long temp = -1 * targetDistances[i];
        targetDistances[i] = -1 * targetDistances[(n - 1) - i];
        targetDistances[(n - 1) - i] = temp;

    }

}

long* targetDistances = targetDistGenerator(numCarts);

int main()
{

    for(uint8_t i = 0; i < n; ++i)
        std::cout << targetDistances[i] << " ";

    std::cout << std::endl;

    reverseDirection(targetDistances, numCarts);

    for(uint8_t i = 0; i < n; ++i)
        std::cout << targetDistances[i] << " ";    

    std::cout << std::endl;

    reverseDirection(targetDistances, numCarts);

    for(uint8_t i = 0; i < n; ++i)
        std::cout << targetDistances[i] << " ";    

    std::cout << std::endl;

    reverseDirection(targetDistances, numCarts);

    for(uint8_t i = 0; i < n; ++i)
        std::cout << targetDistances[i] << " ";    

    std::cout << std::endl;

    return 0;

}
