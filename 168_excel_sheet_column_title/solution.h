#pragma once

#include <string>
#include <algorithm>

class Solution {
public:
    std::string convertToTitle(int n) {
        std::string res;
        while(n) {
            n--;
            int step = n % 26;
            res.push_back('A' + step);
            n /= 26;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
