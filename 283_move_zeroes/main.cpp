#include <iostream>

#include "solution.h"

int main()
{
    std::vector<int> input{ 0, 1, 0, 3, 12 };

    Solution s;
    s.moveZeroes(input);
    std::for_each(input.begin(), input.end(), [](int val){
        std::cout << val << " ";
    });
    std::cout << std::endl;

    return 0;
}
