class Solution:
    def isPalindrome(self, s: str) -> bool:
        pattern = re.compile('[\W_]+')
        s = pattern.sub('', s).lower()
        return s == s[::-1]