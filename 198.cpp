class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        nums[2] += nums[0];
        for (int i = 1; i < nums.size() - 2; i++) {
            nums[i + 2] += max(nums[i], nums[i - 1]);
        }

        return max(nums[nums.size() - 1], nums[nums.size() - 2]);
    }
};