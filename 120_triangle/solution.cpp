class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        for(size_t l = 1; l < triangle.size(); l++)
        {
            auto const& prev = triangle[l - 1];
            auto& curr = triangle[l];

            curr.front() += prev.front();
            curr.back() += prev.back();

            size_t const last = curr.size() - 1;
            for(size_t i = 1; i < last; i++)
            {
                curr[i] += std::min(prev[i], prev[i - 1]);
            }
        }

        int min = std::numeric_limits<int>::max();
        for(auto const e : triangle.back())
        {
            min = std::min(e, min);
        }
        return min;
    }
};

