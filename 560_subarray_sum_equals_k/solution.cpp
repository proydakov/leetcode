class Solution
{
public:
    int subarraySum(vector<int> const& nums, int const k)
    {
        if (nums.empty())
        {
            return 0;
        }

        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for(size_t i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        std::unordered_map<int, int> hash;
        hash.reserve(nums.size());

        int res{};

        for(size_t i = 0; i < nums.size(); i++)
        {
            if (k == prefix[i])
            {
                res += 1;
            }
            auto const it = hash.find(prefix[i] - k);
            if (it != hash.end())
            {
                res += it->second;
            }
            hash[prefix[i]] += 1;
        }

        return res;
    }
};

//
// k = 0
//
// a = 1, -1, 0
// p = 1   0  0
//    [    ]
//    [        ]
//           [ ]
//

