#include "LargeNumber.h"

bool LargeNumber::millerRabinTest(const LargeNumber& n, const LargeNumber& b, int r) {
    // random number generation ramdomly setup
    std::srand(std::time(0));
    // randomly choose an "a" such that 2 <= a <= n-2
    LargeNumber a = generateRandom(n.digits.length() - 2 ) + LargeNumber("2");
    // compute x = a.^d % n
    LargeNumber x = a.powMod(b, n);
    if(x == LargeNumber("1") || x == n - LargeNumber("1")){
        return true;
    }
    // repeat r - 1 times 
    for (int i = 0; i < r - 1; i++) {
        // Update x = x^2 % n
        x = x.powMod(LargeNumber("2"), n);

        // If x == n-1, 'a' is not a witness
        if (x == n - LargeNumber("1")) {
            return true;
        }
    }
    // if 'a' is a witness for the primality of 'n'
    return false;
}