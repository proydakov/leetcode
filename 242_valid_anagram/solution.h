#pragma once

#include <array>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if(s.size() != t.size() ) {
            return false;
        }

        std::array<char, 256> array{ 0 };
        const size_t size = s.size();
        for(size_t i = 0; i < size; i++) {
            array[ s[i] ]++;
            array[ t[i] ]--;
        }
        for(size_t i = size_t('a'); i <= size_t('z'); i++) {
            if(array[i] != 0) {
                return false;
            }
        }
        return true;
    }

private:
    static const size_t alf_size = 26;
};
