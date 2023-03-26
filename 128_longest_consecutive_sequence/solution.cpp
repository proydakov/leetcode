class Solution final
{
public:
    int longestConsecutive(vector<int> const& nums)
    {
        std::unordered_set<int> set;
        set.reserve(nums.size());

        for(auto const n : nums)
        {
            set.insert(n);
        }

        int res{0};

        for(auto const n : nums)
        {
            // we found the beginning of sequence
            if (set.find(n - 1) == set.end())
            {
                int e = n + 1;
                while(set.find(e) != set.end())
                {
                    e++;
                }
                res = std::max(res, e - n);
            }
        }

        return res;
    }
};

