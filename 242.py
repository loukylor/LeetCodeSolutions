class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        counter = {}
        for char in s:
            if char in counter:
                counter[char] += 1
            else:
                counter[char] = 1
        
        for char in t:
            if char in counter:
                counter[char] -= 1
                if counter[char] < 0:
                    return False
                elif counter[char] == 0:
                    del counter[char]
            else:
                return False
        
        return len(counter) == 0
