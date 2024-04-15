class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> permutation;
        vector<vector<int>> res;
        backtrack(nums, permutation, res);
        return res;
    }

private:
    void backtrack(const vector<int>& nums, vector<int>& permutation, vector<vector<int>>& res) {
        if (permutation.size() == nums.size()) {
            res.push_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            bool found = false;
            for (int j = 0; j < permutation.size(); j++) {
                if (permutation[j] == nums[i]) {
                    found = true;
                    break;
                }
            }
            if (found) {
                continue;
            }
            permutation.push_back(nums[i]);
            backtrack(nums, permutation, res);
            permutation.pop_back();
        }
    }
};