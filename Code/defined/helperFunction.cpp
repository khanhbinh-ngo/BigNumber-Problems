#include "LargeNumber.h"

std::ostream& operator<<(std::ostream& os, const LargeNumber& number) {
    os << number.digits;
    return os;
}

// Helper function to convert string to LargeNumber
LargeNumber::LargeNumber(const std::string& str) : digits(str) {}