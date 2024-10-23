class MedianFinder:

    def __init__(self):
        self.low_heap = []
        self.low_len = 0
        self.high_heap = []
        self.high_len = 0

    def addNum(self, num: int) -> None:
        # Insert to the half it is a part of
        median = self.findMedian()
        if num > median:
            heapq.heappush(self.high_heap, num)
            self.high_len += 1
        else:
            heapq.heappush(self.low_heap, -num)
            self.low_len += 1

        # Keep their lengths at most one apart
        if self.high_len - 1 > self.low_len:
            heapq.heappush(self.low_heap, -heapq.heappop(self.high_heap))
            self.high_len -= 1
            self.low_len += 1
        elif self.low_len - 1 > self.high_len:
            heapq.heappush(self.high_heap, -heapq.heappop(self.low_heap))
            self.high_len += 1
            self.low_len -= 1

    def findMedian(self) -> float:
        if self.low_len == self.high_len:
            # No elements, return 0
            if self.low_len == 0:
                return 0
            else:
                # Return even median
                return (-self.low_heap[0] + self.high_heap[0]) / 2
        
        # Return odd median
        elif self.low_len > self.high_len:
            return -self.low_heap[0]
        else:
            return self.high_heap[0]            


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()