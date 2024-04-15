class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, subset, res);
        return vector<vector<int>>(res.begin(), res.end());
    }

private:
    void backtrack(const vector<int>& nums, int j, vector<int>& subset, set<vector<int>>& res) {
        res.insert(subset);

        for (int i = j; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtrack(nums, i + 1, subset, res);
            subset.pop_back();
        }
    }
};