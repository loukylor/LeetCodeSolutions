class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            res[i] = res[i / 2] + i % 2;
        }

        return res;
    }
};