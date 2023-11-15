class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        # count how many times each letter shows up in s1
        # since we only check for permutations, we just need to find
        # a substring with the same number of each letter as s1
        s1_counts = defaultdict(int)
        # zeroes just counts how many values are zero in s1
        zeroes = 0
        for letter in s1:
            s1_counts[letter] += 1
        
        for i in range(len(s2)):
            # if the current letter is in the counter, then subtract it
            if s2[i] in s1_counts:
                letter = s2[i]
                if s1_counts[letter] == 0:
                    zeroes -= 1
                s1_counts[letter] -= 1
                if s1_counts[letter] == 0:
                    zeroes += 1

            # if the letter that just left the sliding window is in the
            # counter, readd it
            if i >= len(s1) and s2[i - len(s1)] in s1_counts:
                letter = s2[i - len(s1)]
                if s1_counts[letter] == 0:
                    zeroes -= 1
                s1_counts[letter] += 1
                if s1_counts[letter] == 0:
                    zeroes += 1

            # if the counter is all zeroes, we have a match
            if len(s1_counts) == zeroes:
                return True
            
        return False
