class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> substrings;
        backtrack(s, 0, res, substrings);
        return res;
    }

private:
    void backtrack(const string& s, int j, vector<vector<string>>& res, vector<string>& substrings) {
        if (j >= s.size()) {
            res.push_back(substrings);
            return;
        }
        
        for (int i = j; i < s.size(); i++) {
            if (!isPalindrome(s, j, i - j + 1)) {
                continue;
            }

            substrings.push_back(s.substr(j, i - j + 1));
            backtrack(s, i + 1, res, substrings);
            substrings.pop_back();
        }
    }

    bool isPalindrome(const string& s, int pos, int len) {
        for (int i = 0; i < len / 2; i++) {
            if (s[pos + i] != s[pos + len - i - 1]) {
                return false;
            }
        }

        return true;
    }
};