class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heapq._heapify_max(stones)

        while len(stones) > 1:
            heavier = heapq._heappop_max(stones)
            lighter = stones[0]

            if heavier != lighter:
                heapq._heapreplace_max(stones, heavier - lighter)
            else:
                heapq._heappop_max(stones)
        return stones[0] if len(stones) > 0 else 0
