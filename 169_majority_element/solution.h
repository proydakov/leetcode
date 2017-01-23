#pragma once

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int major = nums[0];
        size_t counter = 1;
        for(size_t i = 1; i < nums.size(); i++) {
            const int iter = nums[i];
            if(iter == major) {
                ++counter;
            }
            else if(counter == 0) {
                major = iter;
                counter = 1;
            }
            else {
                --counter;
            }
        }
        return major;
    }
};
