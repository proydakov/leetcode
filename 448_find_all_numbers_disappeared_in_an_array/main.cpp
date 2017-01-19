#include <vector>
#include <iostream>
#include "solution.h"

int main()
{
    std::vector<int> input{ 4, 3, 2, 7, 8, 2, 3, 1 };

    Solution s;
    std::vector<int> data = s.findDisappearedNumbers( input );

    for(size_t i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
