class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if (len(s) < len(t)):
            return ""

        left = 0
        right = 0

        count = Counter(t)
        amt_matched = 0

        min_left = 0
        min_right = 1 << 32

        while right < len(s) + 1:
            if (min_right - min_left > right - left and amt_matched == len(count)):
                min_right = right
                min_left = left

            if (amt_matched == len(count)):
                if (s[left] in count):
                    if (count[s[left]] == 0):
                        amt_matched -= 1
                    count[s[left]] += 1

                left += 1

            else:
                if (right >= len(s)):
                    break

                if s[right] in count:
                    count[s[right]] -= 1

                    if (count[s[right]] == 0):
                        amt_matched += 1

                right += 1
        
        if (min_right - min_left > 10**5):
            return ""
        return s[min_left : min_right]