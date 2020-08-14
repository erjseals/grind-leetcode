#include <iostream>
#include <vector>
#include <string>


std::vector<std::string> letterCombinations(std::string digits);

std::vector<std::string> t9 = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main() 
{
    std::vector<std::string> lC;
    std::string input;
    std::cin >> input;
    lC = letterCombinations(input);
    for(auto& a : lC) 
        std::cout << a << ' ';
    std::cout << std::endl;   
}

std::vector<std::string> letterCombinations(std::string digits) 
{
    // Initialize the result vector with an empty string for the base case swap
    std::vector<std::string> res = {""};

    for(int i = 0 ; i < digits.size() ; i++) 
    {
        // Digits need to range between 0 and 9.
        // For example, the ascii value for 3 is 51 and 0 is 48. 51 - 48 is 3.  
        int digit = digits[i] - '0';

        // Only digits 2 to 9 are valid, but I handle 0 and 1 incase user hits those numbers
        if(0 > digit || digit > 9) continue;

        // Use a const ref since we won't change the values.
        const std::string& str = t9[digit]; 

        std::vector<std::string> temp;

        for(int k = 0 ; k < res.size() ; k++) 
            for(int j = 0 ; j < str.size() ; j++) 
                temp.push_back(res[k] + str[j]);

        res.swap(temp);
    }
    return res;
}