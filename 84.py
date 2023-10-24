class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        less_than_left = []
        less_than_right = [0] * len(heights)

        for i in range(len(heights)):
            lower_height_index = i - 1
            while lower_height_index >= 0 and heights[lower_height_index] >= heights[i]:
                lower_height_index = less_than_left[lower_height_index]
            less_than_left.append(lower_height_index)

        for i in range(len(heights) - 1, -1, -1):
            lower_height_index = i + 1
            while lower_height_index < len(heights) and heights[lower_height_index] >= heights[i]:
                lower_height_index = less_than_right[lower_height_index]
            less_than_right[i] = lower_height_index

        max_area = 0
        for i in range(len(heights)):
            width = less_than_right[i] - less_than_left[i] - 1
            max_area = max(max_area, heights[i] * width)

        return max_area