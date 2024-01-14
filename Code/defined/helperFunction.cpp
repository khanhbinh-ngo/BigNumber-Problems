#include "LargeNumber.h"

std::ostream& operator<<(std::ostream& os, const LargeNumber& number) {
    os << number.digits;
    return os;
}

// Helper function to convert string to LargeNumber
LargeNumber::LargeNumber(const std::string& str) : digits(str) {}


// Generate a random LargeNumber for testing
LargeNumber LargeNumber::generateRandom(int size) {
    // ensure different random number with the specified fields
    std::srand(static_cast<unsigned int> (std::time(0) ));
    // generate a randomsize
    std::string randomDigits;
    bool leadingZero = true; // flag to track leading zero;
    for(int i = 0; i < size; i++){
        //generate a fucking random digit between 0 and 9
        char digit = static_cast<char>(std::rand()%10+'0');
        if(leadingZero && digit == '0'){
            continue;
        }
        leadingZero = false;
        randomDigits.push_back(digit);
    }
    // if a number end up with being alll zero, sset it to 1 and avoid  0;
    if(randomDigits.empty()){
        randomDigits.push_back('1');
    }
    return LargeNumber(randomDigits);
}