#pragma once

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        {
            std::sort(nums1.begin(), nums1.end());
        }
        {
            std::sort(nums2.begin(), nums2.end());
        }

        std::vector<int> result;
        result.reserve( std::min( nums1.size(), nums2.size() ) );
        for(size_t i1 = 0, i2 = 0; (i1 < nums1.size()) && (i2 < nums2.size());) {
            if(nums1[i1] < nums2[i2]) {
                i1++;
            }
            else if(nums1[i1] > nums2[i2]) {
                i2++;
            }
            else {
                result.push_back( nums1[i1] );
                ++i1;
                ++i2;
            }
        }

        return result;
    }
};
