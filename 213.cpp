class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } 

        return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
    }

private:
    int rob(vector<int>& nums, int l, int r) {
        int prev = 0, curr = 0;
        for (int i = l; i < r; i++) {
            int temp = curr;
            curr = max(nums[i] + prev, curr);
            prev = temp;
        }
        return max(prev, curr);
    }
};