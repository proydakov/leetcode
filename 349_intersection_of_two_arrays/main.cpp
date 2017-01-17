#include <iostream>

#include "solution.h"

int main()
{
    std::vector<int> ar1{ 1, 2, 2, 1 };
    std::vector<int> ar2{ 2, 2 };

    Solution s;
    auto res = s.intersection(ar1, ar2);
    for(size_t i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
