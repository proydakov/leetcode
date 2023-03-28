class Solution final
{
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        constexpr size_t WI = 0;
        constexpr size_t HI = 1;

        std::sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b)
        {
            return a[WI] == b[WI] ? b[HI] < a[HI] : a[WI] < b[WI];
        });

        std::vector<int> dp(1, envelopes.front()[HI]);

        for(auto const& vec : envelopes)
        {
            auto const heigth = vec[HI];
            if (heigth > dp.back())
            {
                dp.push_back(heigth);
            }
            else
            {
                auto it = std::lower_bound(dp.begin(), dp.end(), heigth);
                *it = heigth;
            }
        }

        return dp.size();
    }
};

