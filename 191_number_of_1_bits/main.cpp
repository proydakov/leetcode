#include <iostream>

#include "solution.h"

int main()
{
    int val = 33;

    Solution s;
    int weight = s.hammingWeight(val);
    std::cout << "val: " << val << " weight: " << weight << std::endl;

    return 0;
}
