#pragma once

class Solution
{
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        for(size_t i = 0; i < nums.size();) {
            const int current = nums[ i ];
            if( current == -1 ) {
                ++i;
            }
            else if( current != i + 1 ) {
                const size_t swap_index = nums[i] - 1;
                const int temp = nums[ swap_index ];
                if(current != temp) {
                    nums[ swap_index ] = current;
                    nums[ i ] = temp;
                }
                else {
                    nums[ i ] = -1;
                }
            }
            else {
                ++i;
            }
        }
        std::vector<int> data;
        data.reserve( nums.size() );
        for(size_t i = 0; i < nums.size(); i++) {
            if(nums[ i ] == -1) {
                data.push_back( i + 1 );
            }
        }
        return data;
    }
};
