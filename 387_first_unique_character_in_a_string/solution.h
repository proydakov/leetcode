#pragma once

#include <array>
#include <string>

class Solution {
public:
    int firstUniqChar(std::string s) {
        const size_t size = s.size();
        std::array<int, 256> buffer;
        buffer.fill(size);
        for(size_t i = 0; i < size; i++) {
            if( size == buffer[ s[i] ] ) {
                buffer[ s[i] ] = i;
            }
            else {
                buffer[ s[i] ] = -1;
            }
        }
        int index = size;
        for(size_t i = 'a'; i <= 'z'; i++) {
            if( buffer[i] < index && buffer[i] > -1 ) {
                index = buffer[i];
            }
        }
        return index == size ? -1 : index;
    }
};
