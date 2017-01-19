#include <iostream>

#include "solution.h"

int main()
{
    const std::vector<std::string> data{
        "A",
        "B",
        "C",
        "Z",
        "AA",
        "AB",
    };

    Solution s;
    for(size_t i = 0; i < data.size(); i++) {
        std::string str = data[i];
        int num = s.titleToNumber(str);
        std::cout << str << " -> " << num << std::endl;
    }

    return 0;
}
