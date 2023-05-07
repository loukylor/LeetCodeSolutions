class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        self._generate_parenthesis(n, 0, "", res)
        return res
    
    def _generate_parenthesis(self, n: int, open_count: int, curr: str, res: List[str]) -> None:
        if len(curr) == n * 2:
            res.append(curr)
            return
        
        if open_count > 0:
            self._generate_parenthesis(n, open_count - 1, curr + ")", res)
        # If length remaining parenthesis is equal to the 
        # number of open parenthesis, we cant add anymore
        if open_count < n * 2 - len(curr):
            self._generate_parenthesis(n, open_count + 1, curr + "(", res)
