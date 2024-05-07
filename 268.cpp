class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int mask = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            mask ^= nums[i] ^ i;
        }

        return mask;
    }
};