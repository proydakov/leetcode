#include <iostream>

#include "solution.h"

int main()
{
    int val = 38;

    Solution s;
    int res = s.addDigits(val);
    std::cout << "val: " << val << " addDigits: " << res << std::endl;

    return 0;
}
