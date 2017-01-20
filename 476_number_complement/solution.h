#pragma once

class Solution
{
public:
    int findComplement(int num) {
        long flag = 1;
        long res = 0;
        while(flag && flag <= num) {
            int temp = flag & num;
            if(temp == 0) {
                res |= flag;
            }
            flag <<= 1;
        }
        return res;
    }
};
