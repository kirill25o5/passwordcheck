#pragma once
#include <iostream>
#include <string>
#include <cmath>

int analizePasswordByLenAndCombinatoryComplexity(const std::string & inputString) 
{


    int upperCaseCount = 0, lowerCaseCount = 0, digitCount = 0, specialCharCount = 0, uniqueCharCount = 0;
    int stringLength = inputString.length();

    for (int i = 0; i < stringLength; i++) {
        char currentChar = inputString[i];
        if (isupper(currentChar)) {
            upperCaseCount++;
        } else if (islower(currentChar)) {
            lowerCaseCount++;
        } else if (isdigit(currentChar)) {
            digitCount++;
        } else {
            specialCharCount++;
        }
    }

    //std::cout << "The total length of the input string is: " << stringLength << std::endl;
    //std::cout << "Number of upper case characters in the string: " << upperCaseCount << std::endl;
    //std::cout << "Number of lower case characters in the string: " << lowerCaseCount << std::endl;
    //std::cout << "Number of digits in the string: " << digitCount << std::endl;
    //std::cout << "Number of special characters in the string: " << specialCharCount << std::endl;
    
    upperCaseCount ? uniqueCharCount += 26 : uniqueCharCount;
    lowerCaseCount ? uniqueCharCount += 26 : uniqueCharCount;
    digitCount ? uniqueCharCount += 10 : uniqueCharCount;
    specialCharCount ? uniqueCharCount += 22 : uniqueCharCount;
    
    //std::cout << "uniqueCharCount: " << uniqueCharCount << std::endl;
    
    double entropy = log2(pow(uniqueCharCount,stringLength));
    //std::cout << "entropy bit: " << entropy << std::endl;
    
    int rating = static_cast<int>((entropy / 128) * 100);

    
    return ((rating>100) ? 100 : rating);
}