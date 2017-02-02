#pragma once

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        long sum = 0;
        for(size_t i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        const size_t len = nums.size();
        long all_sum = len * (len + 1) >> 1;
        return all_sum - sum;
    }
};
