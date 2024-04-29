class Solution {
public:
    int numDecodings(string s) {
        int currCount = 1, lastCount = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                lastCount = currCount;
                currCount = 0;
                continue;
            } 

            int temp = currCount;
            if (i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) {
                temp += lastCount;
            }
            lastCount = currCount;
            currCount = temp;
        }

        return currCount;
    }
};