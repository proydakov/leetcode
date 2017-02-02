#pragma once

#include <limits>

class Solution {
public:
    int reverse(int x) {
        if(x == 0 || x == std::numeric_limits<int>::min()) {
            return 0;
        }
        bool minus = false;
        if(x < 0) {
            minus = true;
            x *= -1;
        }
        long result = 0;
        while(x) {
            const int ost = x % 10;
            x /= 10;
            result = 10 * result + ost;
        }
        if(result > std::numeric_limits<int>::max()) {
            return 0;
        }
        if(minus) {
            result *= -1;
        }
        return result;
    }
};
