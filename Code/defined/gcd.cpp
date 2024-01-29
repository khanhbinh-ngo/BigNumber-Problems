#include "LargeNumber.h"

LargeNumber LargeNumber::gcd(const LargeNumber& other) const {
    LargeNumber firstNum(*this);
    LargeNumber secondNum(other);

    // handle special cases 
    if(firstNum == LargeNumber("0")){
        return secondNum;
    } ;
    if(secondNum == LargeNumber("0")){
        return firstNum;
    }

    //find the comond power of 2
    int comondPower = 0;
    while ((firstNum % LargeNumber("2") == LargeNumber("2")) && ((secondNum % LargeNumber("2")) == LargeNumber("2"))){
        firstNum = firstNum / LargeNumber("2");
        secondNum = secondNum / LargeNumber("2");
        comondPower++;
    }

    while (firstNum != secondNum){
        if(firstNum < secondNum){
            LargeNumber temp = firstNum;
            firstNum = secondNum;
            secondNum = temp;
        }
        firstNum = firstNum - secondNum;
        // divide by 2 until it becomes odd
        while( firstNum % LargeNumber("2") == LargeNumber("0")){
            firstNum = firstNum / LargeNumber("2");
        }
    }

    // multiply back by 2^commonPower
    return firstNum * LargeNumber("2").powMod(LargeNumber(std::to_string(comondPower)), LargeNumber());
}