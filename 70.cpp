class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }

        int last = 1;
        int lastLast = 1;
        int temp;
        for (int i = 2; i < n; i++) {
            temp = last;
            last += lastLast;
            lastLast = temp;
        }

        return last + lastLast;
    }
};