#include "solution.h"

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vals{ 7, -7, 100, -100, 0 };
    for(size_t i = 0; i < vals.size(); i++) {
        int val = vals[i];
        Solution s;
        std::string res = s.convertToBase7(val);

        std::cout << "solve: "
                  << " val: " << val
                  << " res: " << res
                  << std::endl;
    }

    return 0;
}
