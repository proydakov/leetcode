#include <string>
#include <vector>
#include <iostream>

#include "solution.h"

int main()
{
    std::vector<std::pair<std::string, std::string>> data{
        { "aa", "ab" },
        { "ab", "aa" },
        { "egg", "add" },
        { "foo", "bar" },
        { "paper", "title" },
    };

    Solution solution;

    for(size_t i = 0; i < data.size(); i++) {
        const bool is = solution.isIsomorphic(data[i].first, data[i].second);
        std::cout << "" << data[i].first
                  << ", " << data[i].second
                  << " is: " << is
                  << std::endl;
    }

    return 0;
}
