#pragma once

class Solution {
public:
    std::vector<int> constructRectangle(int area) {
        int sq = std::sqrt(area);
        std::vector<int> result{ 0, 0 };

        int pow_ = sq * sq;
        int big   = sq;
        int small = sq;
        
        bool step = true;
        while(pow_ != area) {
            if(step) {
                ++big;
            }
            else {
                --small;
            }
            pow_ = big * small;
            step = pow_ < area;
        }
        result[0] = big;
        result[1] = small;

        return result;
    }
};
