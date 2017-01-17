#pragma once

#include <set>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::set<int> s1{ nums1.begin(), nums1.end() };
        std::set<int> s2{ nums2.begin(), nums2.end() };

        std::vector<int> result;
        result.reserve( std::min(s1.size(), s2.size() ) );
        std::set_intersection(
            s1.begin(), s1.end(),
            s2.begin(), s2.end(),
            std::back_inserter(result)
        );

        return result;
    }
};
