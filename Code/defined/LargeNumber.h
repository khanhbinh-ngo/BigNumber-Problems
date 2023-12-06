#include <iostream>
#include <random>
#include <chrono>
#include <cmath>
#include <cassert>
#include <stdlib.h>
#include <ctime>

class LargeNumber{
    public: 
        // constructor
        LargeNumber() = default;
        explicit LargeNumber(const std::string &str);

        // Arithmetic operator
        LargeNumber operator+(const LargeNumber& other) const;
        LargeNumber operator-(const LargeNumber& other) const;
        LargeNumber operator*(const LargeNumber& other) const;
        LargeNumber operator/(const LargeNumber& other) const;
        LargeNumber operator%(const LargeNumber& other) const;
        LargeNumber &operator=(const LargeNumber& other);

        // Comparison operators
        bool operator==(const LargeNumber& other) const;
        bool operator!=(const LargeNumber& other) const;
        bool operator>=(const LargeNumber& other) const;
        bool operator<=(const LargeNumber& other) const;
        bool operator>(const LargeNumber& other) const;
        bool operator<(const LargeNumber& other) const;

        // friend operator
        friend std::ostream& operator<<(std::ostream& os, const LargeNumber& number);

        // helper function
        static LargeNumber generateRandom(int size);
        static bool millerRabinTest (const LargeNumber& n, const LargeNumber& d, int r);
        
        // other operations
        LargeNumber powMod(const LargeNumber& exponent, const LargeNumber& modulus) const;
        LargeNumber gcd(const LargeNumber& other) const;
        bool isPrime() const;

        // convert LargeNumber to string
        std::string toString() const {
            return digits;
        }
    private:
        //internal representation
        std::string digits;
};

