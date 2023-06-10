class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        res = 0
        for c in columnTitle:
            # If you imagine there just being 10 letters, you can
            # imagine this code as converting letters into base 10
            # to help simplify what's going on
            res = 26 * res + (ord(c) - 64)
            
        return res
