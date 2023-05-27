class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        ones_index = 0
        twos_index = 0
        for i in range(len(nums)):
            num = nums[i]
            nums.pop(i)
            if num == 0:
                nums.insert(0, 0)
                ones_index += 1
                twos_index += 1
            elif num == 1:
                nums.insert(ones_index, 1)
                twos_index += 1
            elif num == 2:
                nums.insert(twos_index, 2)
            else:
                raise ValueError("A value other than 0, 1, or 2 passed into the function.")
