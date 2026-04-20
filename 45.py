class Solution:
    def jump(self, nums: List[int]) -> int:
        i = 0
        steps = 0
        while i < len(nums) - 1:
            if i + nums[i] >= len(nums) - 1:
                return steps + 1

            next_jump = 0
            next_i = i
            for j in range(i + 1, i + 1 + nums[i]):
                if j + nums[j] > next_jump:
                    next_i = j
                    next_jump = j + nums[j]
            
            i = next_i
            steps += 1

        return steps
