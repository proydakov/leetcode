#pragma once

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::set<int> set;
        for(size_t i = 0; i < nums.size(); i++) {
            std::pair<std::set<int>::iterator, bool> insert = set.insert(nums[i]);
            if(insert.second == false) {
                return true;
            }
        }
        return false;
    }
};
