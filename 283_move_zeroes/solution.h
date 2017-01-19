#pragma once

#include <vector>
#include <utility>
#include <algorithm>

class Solution
{
public:
    void moveZeroes(std::vector<int>& nums) {
        size_t num_index = 0;
        for( size_t i = 0; i < nums.size(); i++ ) {
            if(nums[i] != 0) {
                std::swap( nums[i], nums[num_index] );
                num_index++;
            }
        }
    }
};
