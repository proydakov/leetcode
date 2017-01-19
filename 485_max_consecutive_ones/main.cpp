#include <vector>
#include <iostream>
#include "solution.h"

void test(const std::vector<int>& input)
{
    Solution s;
    const int max = s.findMaxConsecutiveOnes(input);
    std::cout << "[";
    for(size_t i = 0; i < input.size() - 1; i++) {
        std::cout << input[i] << ", ";
    }
    if(!input.empty()) {
        std::cout << input[input.size() - 1];
    }
    std::cout << "]" << std::endl;
    std::cout << "max: " << max << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

int main()
{
    {
        const std::vector<int> input{ 0 };
        test(input);
    }

    {
        const std::vector<int> input{ 1 };
        test(input);
    }

    {
        const std::vector<int> input{ 1, 0 };
        test(input);
    }

    {
        const std::vector<int> input{ 0, 1 };
        test(input);
    }

    {
        const std::vector<int> input{ 1, 1, 0, 1, 1, 1 };
        test(input);
    }

    return 0;
}
