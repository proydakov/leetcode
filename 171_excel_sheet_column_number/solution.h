#include <string>
#include <limits>
#include <vector>

class Solution
{
public:
    int titleToNumber(std::string s) {
        int num = 0;
        int step = 1;
        for(size_t i = s.size() - 1; i != std::numeric_limits<size_t>::max(); i--) {
            int temp = (s[i] - 'A' + 1) * step;
            num += temp;
            step *= 26;
        }
        return num;
    }
};
