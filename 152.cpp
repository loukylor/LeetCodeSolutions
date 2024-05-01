class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1;
        int suffix = 1;
        int max_ = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            prefix *= nums[i];
            max_ = max(prefix, max_);
            if (prefix == 0) {
                prefix = 1;
            }

            suffix *= nums[nums.size() - i - 1];
            max_ = max(suffix, max_);
            if (suffix == 0) {
                suffix = 1;
            }
        }

        return max_;
    }
};