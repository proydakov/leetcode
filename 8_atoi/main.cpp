#include <iostream>
#include "solution.h"

int main()
{
    Solution s;

    std::cout << "+-2: " << s.myAtoi("+-2") << std::endl;
    std::cout << "-+1: " << s.myAtoi("-+1") << std::endl;
    std::cout << "123: " << s.myAtoi("123") << std::endl;
    std::cout << "-11: " << s.myAtoi("-11") << std::endl;
    std::cout << "+11: " << s.myAtoi("+11") << std::endl;
    std::cout << "  1: " << s.myAtoi("  1") << std::endl;
    std::cout << "23a8f: " << s.myAtoi("23a8f") << std::endl;

    std::cout << "   -012a42:  " << s.myAtoi("  -0012a42") << std::endl;
    std::cout << "   +004500:  " << s.myAtoi("   +004500") << std::endl;
    std::cout << " 2147483648: " << s.myAtoi("2147483648") << std::endl;
    std::cout << " 2147483649: " << s.myAtoi("2147483649") << std::endl;

    std::cout << "-2147483648: " << s.myAtoi("-2147483648") << std::endl;
    std::cout << "-2147483649: " << s.myAtoi("-2147483649") << std::endl;

    std::cout << " b11228552307: " << s.myAtoi(" b11228552307") << std::endl;
    std::cout << "+9223372036854775809: " << s.myAtoi("+9223372036854775809") << std::endl;
    std::cout << "-9223372036854775809: " << s.myAtoi("-9223372036854775809") << std::endl;

    return 0;
}
