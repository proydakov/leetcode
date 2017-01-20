#include <string>
#include <vector>
#include <iostream>

#include "solution.h"

int main()
{
    int input = 15;

    Solution solution;

    std::vector<std::string> result = solution.fizzBuzz(input);
    for(size_t i = 0; i < result.size(); i++) {
        std::cout << result[i] << std::endl;
    }

    return 0;
}
