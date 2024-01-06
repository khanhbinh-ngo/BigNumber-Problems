#include "LargeNumber.h"
bool LargeNumber::operator==(const LargeNumber& other) const {
    return digits == other.digits;
}
bool LargeNumber::operator!=(const LargeNumber& other) const {
    return digits != other.digits;
}
bool LargeNumber::operator>=(const LargeNumber& other) const {
    return !(*this < other);
}

bool LargeNumber::operator<(const LargeNumber& other) const {
    if(digits.length() < other.digits.length()){
        return true;
    } else if(digits.length() > other.digits.length()) {
        return false;
    }
    return digits < other.digits;
}
bool LargeNumber::operator>(const LargeNumber& other) const {
    return !(*this < other) && !(*this == other);
}

bool LargeNumber::operator<=(const LargeNumber& other) const {
    // Compare the digits of the two numbers
    return digits.length() < other.digits.length() ||
           (digits.length() == other.digits.length() && digits <= other.digits);
}