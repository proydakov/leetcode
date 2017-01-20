#pragma once

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, size_t> counterRansomNote;
        make_map(ransomNote, counterRansomNote);

        std::unordered_map<char, size_t> counterMagazine;
        make_map(magazine, counterMagazine);

        auto magazine_end_it = counterMagazine.end();
        auto end_it = counterRansomNote.end();
        for(auto it = counterRansomNote.begin(); it != end_it ; ++it) {
            auto search_it = counterMagazine.find( it->first );
            if(search_it == magazine_end_it || search_it->second < it->second) {
                return false;
            }
        }
        
        return true;
    }

private:
    void make_map(const std::string& str, std::unordered_map<char, size_t>& map)
    {
        for(size_t i = 0; i < str.size(); i++) {
            map[ str[i] ]++;
        }
    }
};
