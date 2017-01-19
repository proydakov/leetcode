#include <iostream>

#include "solution.h"

int main()
{
    int val = 2 >> 1;
    std::cout << "val: " << val << std::endl;

    Solution s;
    bool is = s.isPerfectSquare(9);
    std::cout << "is: " << is << std::endl;
    return 0;
}
