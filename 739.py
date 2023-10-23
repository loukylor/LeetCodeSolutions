class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        res = [0] * len(temperatures)
        for i, temp in zip(range(len(temperatures)), temperatures):
            while len(stack) > 0 and stack[-1][1] < temp:
                org_i = stack.pop()[0]
                res[org_i] = i - org_i
            stack.append((i, temp))
        return res
