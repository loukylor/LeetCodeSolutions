class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> subset;
        vector<vector<int>> res;
        backtrack(candidates, target, 0, subset, res);

        return res;
    }

private:
    void backtrack(const vector<int>& candidates, int target, int pos, vector<int>& subset, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        for (int i = pos; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                // candidates are sorted, so everything after will be bigger
                break;
            }

            subset.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, subset, res);
            subset.pop_back();
        }
    }
};