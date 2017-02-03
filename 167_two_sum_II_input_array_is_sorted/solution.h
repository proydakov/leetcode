#pragma once

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        size_t i = 0;
        size_t j = numbers.size() - 1;
        for(;;) {
            const int sum = numbers[i] + numbers[j];
            if( sum < target ) {
                ++i;
            }
            else if( sum > target) {
                --j;
            }
            else {
                break;
            }
        }
        std::vector<int> solution{ i + 1, j + 1 };
        return solution;
    }
};
