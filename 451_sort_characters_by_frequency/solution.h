#pragma once

class Solution {
public:
    std::string frequencySort(std::string s) {
        std::array<int, 256> array{ 0 };
        array.fill(0);

        const size_t size = s.size();
        for(size_t i = 0; i < size; i++) {
            array[ s[i] ]++;
        }

        std::map<int, std::vector<char>> map;
        for(size_t i = 0; i < 256; i++) {
            if(array[i] > 0) {
                map[ array[i] ].push_back( char(i) );
            }
        }

        std::string result;
        result.reserve(s.size());
        for(auto it = map.rbegin(), end_it = map.rend(); it != end_it; ++it) {
            const size_t count = it->first;
            const auto& vec = it->second;
            for(size_t i = 0; i < vec.size(); i++) {
                for(size_t c = 0; c < count; c++) {
                    result.push_back(vec[i]);
                }
            }
        }
        return result;
    }
};
