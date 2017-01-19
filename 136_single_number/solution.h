#pragma once

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int item = 0;
        for(size_t i = 0; i < nums.size(); i++) {
            item ^= nums[i];
        }
        return item;
    }
};
