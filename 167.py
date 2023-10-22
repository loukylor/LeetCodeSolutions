class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        back = 0
        front = len(numbers) - 1
        while back < front:
            curr = numbers[back] + numbers[front]
            if curr == target:
                return [back + 1, front + 1]
            elif curr > target:
                front -= 1
            else:
                back += 1
        return []
