#pragma once

class Solution {
public:
    std::vector<int> constructRectangle(int area) {
        int width = std::sqrt(area);

        while( area % width != 0 ) {
            --width;
        }
        std::vector<int> result{ area / width, width };
        return result;
    }
};
