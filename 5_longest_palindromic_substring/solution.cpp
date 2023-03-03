class Solution
{
public:
    string longestPalindrome(string const& s)
    {
        if (s.empty())
        {
            return s;
        }

        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));
        for(size_t i = 0; i < s.size(); i++)
        {
            dp[i][i] = true;
        }

        std::string_view const v(s);
        std::string_view res = v.substr(0, 1);

//
//   b a b a d
// b 1 0 1 0 0
// a   1 0 1 0
// b     1 0 1
// a       1 0
// d         1
//

        for(int64_t i = s.size() - 1; i >= 0; i--)
        {
            for(int64_t j = i + 1; j < s.size(); j++)
            {
                if (v[i] == v[j] and ((i + 1) == j or dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;
                    auto const length = j - i + 1;
                    if (length > res.size())
                    {
                        res = v.substr(i, length);
                    }
                }
            }
        }

        return std::string(res);
    }
};

