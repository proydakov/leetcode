#include <vector>
#include <iostream>
#include "solution.h"

int main()
{
    std::vector< std::vector<int> > zero{};

    std::vector< std::vector<int> > data{
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0},
    };

    Solution s;
    int perimeter_zero = s.islandPerimeter(zero);
    std::cout << "perimeter zero: " << perimeter_zero << std::endl;

    int perimeter_data = s.islandPerimeter(data);
    std::cout << "perimeter data: " << perimeter_data << std::endl;

    return 0;
}
