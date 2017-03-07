class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;
        for(; i <= j; ) {
            if(val == nums[i]) {
                std::swap(nums[i], nums[j]);
                --j;
            }
            else {
                ++i;
            }
        }
        return j + 1;
    }
};
