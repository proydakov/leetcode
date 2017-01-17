#pragma once

class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        char c = 0;
        for(size_t i = 0; i < s.size(); i++) {
            c ^= s[i];
        }
        for(size_t i = 0; i < t.size(); i++) {
            c ^= t[i];
        }
        return c;
    }
};
