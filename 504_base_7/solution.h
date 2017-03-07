#include <list>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::string convertToBase7(int num) {
        int base = 7;
        return output_number(num, base);
    }

private:
    std::string output_number(int num, int base)
    {
        std::string str;
        str.reserve(32);

        bool append_minus = false;
        if(num < 0) {
            append_minus = true;
            num *= -1;
        }

        do {
            str.push_back(num % base + '0');
            num /= base;
        }
        while(num != 0);

        if(append_minus) {
            str.push_back('-');
        }

        std::reverse(str.begin(), str.end());

        return str;
    }
};
