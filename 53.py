class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        total = 0
        max_total = -(1 << 64)

        for num in nums:
            if total < 0:
                total = num
            else:
                total += num

            if total > max_total:
                max_total = total

        return max_total
