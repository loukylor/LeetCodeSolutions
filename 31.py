class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        curr = -1
        next_biggest = -1
        for i in range(len(nums) - 1):
            # Check if nums are out of order
            if nums[i] < nums[i + 1]:
                curr = i
                next_biggest = i + 1

            # Check if num at index is the new next_biggest
            elif (curr != -1 
                # It's important that the <= is not < here since it would lead
                # to the wrong number being swapped
                and nums[curr] < nums[i + 1] <= nums[next_biggest]
            ):
                next_biggest = i + 1
        
        # If the nums are all in the right order, then reverse
        if curr == -1:
            nums.reverse()

        # If one or more nums are out of order then reorder
        else:
            nums[curr], nums[next_biggest] = nums[next_biggest], nums[curr]
            nums[curr + 1:] = reversed(nums[curr + 1:])
