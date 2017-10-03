#include <vector>
#include <iostream>

#include "solution.h"

int main()
{
    std::ios::sync_with_stdio(false);
    std::vector<int> data{ 7, 0, 3, 9, 9, 9, 1, 7, 2, 3 };

    Solution s;
    auto solution = s.medianSlidingWindow(data, 6);

    for(const auto& val : solution) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;

    return 0;
}
