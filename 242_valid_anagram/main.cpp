#include <string>
#include <iostream>

#include "solution.h"

void isAnagram(Solution& solution, std::string& s, std::string& t)
{
    bool is = solution.isAnagram(s, t);
    std::cout << "isAnagram: '" << s << "', '" << t << "' res: " << is << std::endl;
}

int main()
{
    Solution solution;

    {
        std::string s = "anagram";
        std::string t = "nagaram";
        isAnagram(solution, s, t);
    }

    {
        std::string s = "rat";
        std::string t = "car";
        isAnagram(solution, s, t);
    }

    return 0;
}
