class Solution final
{
public:
    int minDistance(string const& word1, string const& word2)
    {
        size_t const s1 = word1.size();
        size_t const s2 = word2.size();

        std::vector<std::vector<int>> dp(s1 + 1, std::vector<int>(s2 + 1, 0));

        for(size_t i1 = 1; i1 <= s1; i1++)
        {
            dp[i1][0] = i1;
        }

        for(size_t i2 = 1; i2 <= s2; i2++)
        {
            dp[0][i2] = i2;
        }

        for(size_t i1 = 1; i1 <= s1; i1++)
        {
            for(size_t i2 = 1; i2 <= s2; i2++)
            {
                // same symbol
                if (word1[i1 - 1] == word2[i2 - 1])
                {
                    dp[i1][i2] = dp[i1 - 1][i2 - 1];
                }
                // different symbol
                else
                {
                    dp[i1][i2] = std::min({
                        dp[i1 - 1][i2 - 1],
                        dp[i1 - 1][i2],
                        dp[i1][i2 - 1]
                    }) + 1;
                }
            }
        }

        return dp[s1][s2];
    }
};

//
//   | r o s
// - 0 1 2 3
// h 1 1 2 3
// o 2 2 1 2
// r 3 2 2 2
// s 4 3 3 2
// e 5 4 4 3
//

