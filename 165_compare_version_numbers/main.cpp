#include <vector>
#include <string>
#include <iostream>

#include "solution.h"

int main()
{
    const std::vector<std::string> data{
        "1.0.1",
        "1",
//        "0.1",
//        "1.1",
//        "1.2",
//        "13.37",
    };

    Solution solution;
    for(size_t i = 0; i < data.size(); i++ ) {
        for(size_t j = 0; j < data.size(); j++) {
            int compare = solution.compareVersion(data[i], data[j]);
            std::cout << data[i] << ", " << data[j] << ": " << compare << std::endl;
        }
    }
    return 0;
}
