#include "LargeNumber.h"
LargeNumber LargeNumber::powMod(const LargeNumber& exponent, const LargeNumber& modulus) const {
    LargeNumber result("1");
    LargeNumber base(*this);
    LargeNumber two("2");  
    LargeNumber zero ("0");
    LargeNumber one("1");
    LargeNumber modifiedExponent = exponent; // create a local variable

    while(modifiedExponent != two){ 
        if((modifiedExponent % two) == one){
            result = (result*base) % modulus;
        }
        base = (base * base) % modulus;
        modifiedExponent = modifiedExponent / two;  // update the local variable 
    }
    return result;
}