#pragma once

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> result;
        result.reserve(n);
        for(int i = 1; i <= n; i++) {
            if(0 == i % 15) {
                result.push_back("FizzBuzz");
            }
            else if(0 == i % 3) {
                result.push_back("Fizz");
            }
            else if(0 == i % 5) {
                result.push_back("Buzz");
            }
            else {
                result.push_back(std::to_string(i));
            }
        }
        return result;
    }
};
