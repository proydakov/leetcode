#pragma once

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        size_t i = 0;
        for(size_t j = 1; j < nums.size(); ++j) {
            if(nums[i] != nums[j]) {
                ++i;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
