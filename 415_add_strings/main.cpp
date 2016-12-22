#include <iostream>
#include "solution.h"

int main()
{
    Solution s;

    {
        std::string s1{ "125" };
        std::string s2{  "75" };

        std::string res = s.addStrings(s1, s2);

        std::cout << "sum: " << s1 << " + " << s2 << std::endl;
        std::cout << "res: '" << res << "'" << std::endl;
    }

    {
        std::string s1{ "9" };
        std::string s2{ "1" };

        std::string res = s.addStrings(s1, s2);

        std::cout << "sum: " << s1 << " + " << s2 << std::endl;
        std::cout << "res: '" << res << "'" << std::endl;
    }

    return 0;
}
