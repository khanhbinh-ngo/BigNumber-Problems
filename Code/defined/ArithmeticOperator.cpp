#include "LargeNumber.h"
LargeNumber LargeNumber::operator+(const LargeNumber& other) const {
    // create a result LargeNumber initialized to 0
    LargeNumber result("0");
    // ensure both numbers have the same size by padding with zeroa
    int maxSize = std::max(digits.size(), other.digits.size());
    std::string paddedThis = digits;
    std::string paddedOther = other.digits;
    paddedThis.insert(0, maxSize - digits.size(), '0');
    paddedOther.insert(0, maxSize - other.digits.size(), '0');

    // perform addition digit by digits
    int carry = 0;
    for(int i = maxSize-1;i>=0;i--){
        int digitSum = carry + (paddedThis[i] - '0') + (paddedOther[i] - '0'); 
        carry = digitSum / 10;
        result.digits.insert(result.digits.begin(), (digitSum % 10) + '0');
        // for each + '0' just to modify some thing special
    }
    // if there's a carry left, add it to the front
    if (carry){
        result.digits.insert(result.digits.begin(), carry + '0');
    }
    return result;
}

LargeNumber LargeNumber::operator-(const LargeNumber& other) const {
    std::string resultString;
    std::string paddedThis = digits;
    std::string paddedOther = other.digits;
    size_t maxLength = std::max(digits.length(), other.digits.length());
    paddedThis = std::string(maxLength - paddedThis.length(), '0') + paddedThis;
    paddedOther = std::string(maxLength - paddedOther.length(), '0') + paddedOther;
    int borrow = 0;
    // initialize variablesa
    // subtract each pair of digits along with borrow
    for(int i = maxLength - 1; i >= 0; i--){
        int digitThis = paddedThis[i] - '0';
        int digitOther = paddedOther[i] - '0';
        // applied borrow from the previous step
        digitThis -= borrow;
        // check if we need to borrow from the higher digit
        if(digitOther > digitThis){
            digitThis += 10;
            borrow = 1;
        }else{
            borrow = 0;
        }
        int digitResult = digitThis - digitOther;
        resultString = std::to_string(digitResult) + resultString;
    }
    resultString.erase(0, std::min(resultString.find_first_not_of('0'), resultString.size() - 1));
    return LargeNumber(resultString);
}

LargeNumber LargeNumber::operator*(const LargeNumber& other) const {
    const std::string &BigNumber_1 = digits;
    const std::string &BigNumber_2 = other.digits;
    int Numlength_1 = BigNumber_1.size();
    int Numlength_2 = BigNumber_2.size(); 
    //result will have at most NumLength_1 + NumLength_2 digits 

    std::vector<int>  FinalResult(Numlength_1 + Numlength_2, 0);
    for (int i = Numlength_1 - 1; i >= 0; i--) {
        for(int j = Numlength_2 - 1;i >= 0; i--){
            int mul1 = (BigNumber_1[i] - '0') * (BigNumber_2[j] - '0'); 
            int Sum = mul1 + FinalResult[i+j+1];
            FinalResult[i+j+1] = Sum % 10;
            FinalResult[i+j] += Sum / 10;
        }
    }
    // convert the result to string and after that convert to LargeNumber
    std::string MultiplicationResult;
    for(int digit : FinalResult){
        if(!(MultiplicationResult.empty() && digit == 0)){
            MultiplicationResult.push_back(digit + '0');
        }
    }
    return MultiplicationResult.empty() ? LargeNumber("0") : LargeNumber(MultiplicationResult);
} 

LargeNumber LargeNumber::operator/(const LargeNumber& other) const {
    // handling division by zero
    if(other == LargeNumber("0")){
        throw std::invalid_argument("division by zero");
    }
    LargeNumber quotient;
    LargeNumber remainder(*this);
    LargeNumber currentQuotien = remainder / other;
    remainder = remainder - other * currentQuotien;
    while(remainder >= other){
        currentQuotien = remainder / other;
        remainder = remainder - other * currentQuotien;
        quotient = quotient + currentQuotien;
    }
    return quotient;
}

LargeNumber LargeNumber::operator%(const LargeNumber& other) const {
    // handling modulus by zero
    if(other == LargeNumber("0")){
        throw std::invalid_argument("modulus by zero");
    }

}