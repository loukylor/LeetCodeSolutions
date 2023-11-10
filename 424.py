class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left = 0
        longest = k

        most_chars = 0
        count = defaultdict(int)
        for i in range(len(s)):
            # update chars and most_chars
            count[s[i]] += 1
            if count[s[i]] > most_chars:
                most_chars = count[s[i]]

            # if the window size exceeds the number of the most common 
            # char + k, then move left
            if i - left + 1 > most_chars + k:
                # this is still O(N) since count can't exceed 26 entries
                most_chars = max(count.values())
                count[s[left]] -= 1
                left += 1

            if i - left + 1 > longest:
                longest = i - left + 1
            
        return longest
