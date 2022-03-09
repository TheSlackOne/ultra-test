#ifndef EXERCISE_1
#define EXERCISE_1

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

int64_t add(int64_t a, int64_t b) {
    // Overflow and Underflow detection.
    if ((b > 0) && (a > std::numeric_limits<int64_t>::max() - b))
        throw std::invalid_argument("Overflow detected.");
    if ((b < 0) && (a < std::numeric_limits<int64_t>::min() - b))
        throw std::invalid_argument("Underflow detected.");
    // Addition operation.
    int64_t rest = 0;
    while (b) {
        rest = a & b;
        a = a ^ b;
        b = rest << 1;
    }
    return a;
}

#endif  // EXERCISE_1
