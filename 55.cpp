class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastTrue = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] + i >= lastTrue) {
                lastTrue = i;
                nums[i] = 1;
            } else {
                nums[i] = 0;
            }
        }

        return nums[0] == 1;
    }
};