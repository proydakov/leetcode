#include <string>
#include <iostream>

#include "solution.h"

int main()
{
    std::string s = "qwerty";
    std::string t = "ertyqwi";

    Solution solution;
    const char c = solution.findTheDifference(s, t);
    std::cout << "diff: " << c << std::endl;

    return 0;
}
