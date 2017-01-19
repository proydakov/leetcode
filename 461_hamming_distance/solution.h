#pragma once

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int dist = 0;
        while(n)
        {
            ++dist;
            n &= n - 1;
        }
        return dist;
    }
};
