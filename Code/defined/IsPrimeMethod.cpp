#include "LargeNumber.h"


// Check if a number is prime using Miller-Rabin primality test
bool LargeNumber::isPrime() const {
    // handle special cases
    if(*this == LargeNumber("2") || *this == LargeNumber("3")) {
        return true;
    }

    // check if the number is even or less than 2
    if(*this < LargeNumber("2") || this->digits.back() % 2 == 0){
        return false;
    } 

    // write n as 2^r * d + 1 
    LargeNumber d = *this - LargeNumber("1");
    int r = 0;
    while (d.digits.back() % 2 == 0) {
        d = d / LargeNumber("2");
        r++;
    }

    // run the mille-rabin test for arcuracy 
    const int k = 10; // number of test intergrations
    for (int i = 0; i  < k; i++){
        if(!millerRabinTest(*this, d , r)) {
            return false;
        }
    }
   return true;
}

