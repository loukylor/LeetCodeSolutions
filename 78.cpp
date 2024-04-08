class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        subsets(nums, 0, res, curr);
        return res;
    }

    void subsets(const vector<int>& nums, int l, vector<vector<int>>& res, vector<int>& curr) {
        res.push_back(curr);
        for (int i = l; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            subsets(nums, i + 1, res, curr);
            curr.pop_back();
        }
    }
};