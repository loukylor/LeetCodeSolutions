class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool* dp = new bool[s.size() + 1] { false };
        dp[0] = true;

        for (int i = 0; i < s.size(); i++) {
            if (!dp[i]) {
                continue;
            }

            for (int j = 0; j < wordDict.size(); j++) {
                string word = wordDict[j];
                if (i + word.size() > s.size() || dp[i + word.size()]) {
                    continue;
                }

                dp[i + word.size()] = true;
                for (int k = 0; k < word.size(); k++) {
                    if (word[k] != s[i + k]) {
                        dp[i + word.size()] = false;
                        break;
                    }
                }
            }
        }

        return dp[s.size()];
    }
};