#include "LargeNumber.h"

// Generate a random large number of the specified size
LargeNumber LargeNumber::generateRandom(int size) {

    // Ensure different random numbers on each run
    std::srand(static_cast<unsigned int>(std::time(0)));
    // Generate a random large number with the specified size
    std::string randomDigits;
    bool leadingZero = true;  // Flag to track leading zeros
    for (int i = 0; i < size; ++i) {
        // Generate a random digit between 0 and 9
        char digit = static_cast<char>(std::rand() % 10 + '0');
        // Avoid leading zeros
        if (leadingZero && digit == '0') {
            continue;
        }
        // If a non-zero digit is encountered, set the flag to false
        leadingZero = false;
        randomDigits.push_back(digit);
    }

    // If the number ends up being all zeros, set it to "1" to avoid "0" result
    if (randomDigits.empty()) {
        randomDigits.push_back('1');
    }
    return LargeNumber(randomDigits);
}