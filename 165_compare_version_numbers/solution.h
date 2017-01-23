#pragma once

#include <sstream>

struct version
{
    version(std::string str) :
        ver_(str)
    {
    }

    bool operator<(const version& other) const
    {
        char c{'.'};
        int step1_;
        int step2_;
        std::istringstream stream1(ver_);
        std::istringstream stream2(other.ver_);

        while(c == '.') {
            c = '*';
            step1_ = 0;
            step2_ = 0;

            stream1 >> step1_;
            stream1 >> c;

            stream2 >> step2_;
            stream2 >> c;

            if(step1_ < step2_) {
                return true;
            }
            else if(step1_ > step2_) {
                return false;
            }
        }
        return false;
    }

    std::string ver_;
};

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        version v1(version1);
        version v2(version2);

        if(v2 < v1) {
            return 1;
        }
        else if(v1 < v2) {
            return -1;
        }
        return 0;
    }
};
