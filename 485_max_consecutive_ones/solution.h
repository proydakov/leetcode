#pragma once

class Solution
{
public:
    int findMaxConsecutiveOnes(const std::vector<int>& nums) {
        return findMaxConsecutive( nums, 1 );
    }

private:
    int findMaxConsecutive(const std::vector<int>& nums, int search) {
        int max = 0;
        size_t begin_index = 0;
        for(size_t i = 0; i < nums.size(); i++) {
            if( nums[i] != search ) {
                int max_test = i - begin_index;
                max = std::max( max, max_test );
                begin_index = i + 1;
            }
        }
        if(nums[ nums.size() - 1 ] == search) {
            int max_test = nums.size() - begin_index;
            max = std::max( max, max_test );
        }
        return max;
    }
};
