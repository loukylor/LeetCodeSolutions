class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # binary search, but treat it as a list rather than a matrix
        l = 0
        r = len(matrix) * len(matrix[0]) - 1
        m = 0
        while l < r:
            m = l + ((r - l) // 2)
            col = m % len(matrix[0])
            row = m // len(matrix[0])
            # print(l, r, m, row, col)

            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                r = m - 1
            else:
                l = m + 1
        
        col = l % len(matrix[0])
        row = l // len(matrix[0])
        # print(l, r, row, col)
        if matrix[row][col] == target:
            return True
        return False