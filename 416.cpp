class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        bool dp[sum / 2 + 1];
        fill_n(dp, sum / 2 + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum / 2; j >= nums[i]; j--) {
                if (dp[j - nums[i]]) {
                    dp[j] = true;
                }
            }
        }

        return dp[sum / 2];
    }
};