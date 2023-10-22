class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) == 0:
            return 0

        left = 0
        right = left + 1
        last_trapped_water = 0
        trapped_water = 0
        can_return = True

        while left <= right < len(height):
            # Add water height if right is shorter than left
            if height[right] < height[left]:
                trapped_water += height[left] - height[right]

                # If right is on the last one then there is no corresponding
                # wall to trap water, so we need to advance from the right
                # to calculate the trapped water
                if right == len(height) - 1 and right:
                    can_return = False

            # If right is taller or equal, set left to that and repeat
            else:
                last_trapped_water = trapped_water
                left = right
            
            right += 1

        if can_return:
            return trapped_water

        # Since there was no wall the stuff calculated from the last wall
        # isn't valid
        trapped_water = last_trapped_water 
        
        # Do the same thing but from right
        end = left
        right = len(height) - 1
        left = right - 1
        while left <= right > end:
            print(f"{left}, {right}, {trapped_water}")
            if height[right] > height[left]:
                trapped_water += height[right] - height[left]
            else: 
                right = left
            left -= 1

        return trapped_water