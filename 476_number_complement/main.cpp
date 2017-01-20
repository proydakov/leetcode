#include <vector>
#include <iostream>

#include "solution.h"

int main()
{
    std::vector<int> input{
        5,
        1
    };

    Solution solution;
    for(size_t i = 0; i < input.size(); i++) {
        int result = solution.findComplement( input[ i ] );
        std::cout << "input: " << input[i] << " result: " << result << std::endl;
    }

    return 0;
}
