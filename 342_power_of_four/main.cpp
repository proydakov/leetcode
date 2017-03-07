#include <limits>
#include <iostream>

int main()
{
    long i = 1;
    long max = std::numeric_limits<int>::max();
    while(i < max) {
        std::cout << "case " << i << ":\n";
        i *= 4;
    }

    return 0;
}
