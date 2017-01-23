#pragma once

#include <array>
#include <string>

class Solution
{
public:
    bool isIsomorphic(std::string s, std::string t) {
        if(s.size() != t.size()) {
            return false;
        }

        std::array<char, 256> array12{ 0 };
        std::array<char, 256> array21{ 0 };
        for(size_t i = 0; i < s.size(); i++) {
            if(array12[ t[i] ] == 0) {
                array12[ t[i] ] = s[i];
            }
            else {
                if( array12[ t[i] ] != s[i] ) {
                    return false;
                }
            }

            if(array21[ s[i] ] == 0) {
                array21[ s[i] ] = t[i];
            }
            else {
                if( array21[ s[i] ] != t[i] ) {
                    return false;
                }
            }
        }
        return true;
    }
};
