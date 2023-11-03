class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)
        speed = l + ((r - l) // 2)
        while l <= r:
            speed = l + ((r - l) // 2)

            hours_taken = sum(math.ceil(pile / speed) for pile in piles)
            if hours_taken <= h:
                r = speed - 1
            else:
                l = speed + 1
        
        return l
