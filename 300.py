class Solution:
      def solution_1(self, nums: List[int]) -> int:
        dp = [1] * len(nums)
        
        overall_max = 0
        for i in range(len(nums) - 1, -1, -1):
            max_len = 1
            for k in range(i + 1, len(nums)):
                if nums[k] > nums[i] and dp[k] + 1 > max_len:
                    max_len = dp[k] + 1
            dp[i] = max_len
            
            if max_len > overall_max:
                overall_max = max_len
        
        return overall_max
      
    def solution_2(self, nums: List[int]) -> int:
        size = 0
        
        # Loop through nums
        for num in nums:
            # If current num is larger than the upper bound
            # of our current subsequence, add it to the list
            if size == 0 or num > nums[size - 1]:
                nums[size] = num
                size += 1
                continue
            
            # Search for num to replace in subsequence
            l, r = 0, size - 1
            while l != r:
                m = l + (r - l) // 2
                if nums[m] >= num:
                    r = m
                else:
                    l = m + 1
            nums[l] = num
        
        return size
