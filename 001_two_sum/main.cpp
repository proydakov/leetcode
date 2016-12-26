class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        map.reserve( nums.size() );
        
        for(size_t i = 0; i < nums.size(); i++) {
            map[ nums[i] ] = i;
        }
        
        const auto end_it = map.end();
        for(size_t i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];
            const auto it = map.find(temp);
            if(it != end_it && it->second != i) {
                return std::vector<int>{i, it->second};
            }
        }
        
        return std::vector<int>{-1, -1};
    }
};