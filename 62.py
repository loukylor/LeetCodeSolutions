class Solution:
    def __init__(self):
        self.memoize: Dict[Tuple[int, int], int] = {}
            
    def uniquePaths(self, m: int, n: int) -> int:
        point = (m, n)
        if m == 1 or n == 1:
            self.memoize[point] = 1 
        
        elif point not in self.memoize:
            self.memoize[point] = self.uniquePaths(m - 1, n) + self.uniquePaths(m, n - 1)
        
        return self.memoize[point]
