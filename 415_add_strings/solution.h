#include <string>
#include <algorithm>

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        std::string res;

        res.reserve( std::max(num1.size(), num2.size()) );

        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();

        auto end_it1 = num1.rend();
        auto end_it2 = num2.rend();

        int plus_one = 0;
        for(; it1 != end_it1 && it2 != end_it2; it1++, it2++) {
            int n1 = getNum(*it1);
            int n2 = getNum(*it2);
            int n = n1 + n2 + plus_one;

/*
            std::cout << "num1[i]: " << *it1 << std::endl;
            std::cout << "num2[i]: " << *it2 << std::endl;
            std::cout << "n1: " << n1 << std::endl;
            std::cout << "n2: " << n2 << std::endl;
            std::cout << "n: " << n << std::endl;
*/

            plus_one = getPlusOne(n);
            res.push_back(getChar(n % 10));
        }

        for(; it1 != end_it1; it1++) {
            int n = getNum(*it1) + plus_one;
            plus_one = getPlusOne(n);
            res.push_back(getChar(n % 10));
        }

        for(; it2 != end_it2; it2++) {
            int n = getNum(*it2) + plus_one;
            plus_one = getPlusOne(n);
            res.push_back(getChar(n % 10));
        }

        if(plus_one) {
            res.push_back(getChar(plus_one));
        }

        std::reverse(res.begin(), res.end());
        return res;
    }

private:
    int getNum(char c)
    {
        return (int)c - 48;
    }

    char getChar(int n)
    {
        return char(n + 48);
    }

    int getPlusOne(int n)
    {
        int res = 0;
        if(n > 9) {
            res = 1;
        }
        return res;
    }
};
