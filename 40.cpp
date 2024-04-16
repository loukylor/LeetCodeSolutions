class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> solution;
        vector<vector<int>> res;
        subset(candidates, target, 0, solution, res);

        return res;
    }

private:
    void subset(const vector<int>& candidates, int target, int j, vector<int>& solution, vector<vector<int>>& res) {
        if (target < 0) {
            return;
        }
        else if (target == 0) {
            res.push_back(solution);
            return;
        }

        for (int i = j; i < candidates.size(); i++) {
            // This path will be explored by the recursion, no need to
            // consider it here
            if (i > j && candidates[i] == candidates[i - 1]) {
                continue;
            }
            solution.push_back(candidates[i]);
            subset(candidates, target - candidates[i], i + 1, solution, res);
            solution.pop_back();
        }
    }
};