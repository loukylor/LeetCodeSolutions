class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        fleets = 0

        zipped_sorted = sorted(zip(position, speed))
        curr_time = 0
        for pos, speed in reversed(zipped_sorted):
            time = float(target - pos) / speed
            if time > curr_time:
                curr_time = time
                fleets += 1

        return fleets
