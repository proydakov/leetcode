#include <set>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        multiset<int> set;
        for(size_t i = 0; i < k; i++)
        {
            set.insert(nums[i]);
        }

        vector<int> res;
        res.push_back(*set.rbegin());

        for(size_t i = k; i < nums.size(); i++)
        {
            auto it = set.find(nums[i - k]);
            set.erase(it);
            set.insert(nums[i]);

            res.push_back(*set.rbegin());
        }

        return res;
    }
};

