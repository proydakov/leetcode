#pragma once

class Solution
{
public:
    int hammingWeight(uint32_t n) {
        int dist = 0;
        while(n)
        {
            ++dist;
            n &= n - 1;
        }
        return dist;
    }
};
