class Solution:
    def solution1(self, citations: List[int]) -> int:
        # Set initial variables 
        counter = [0] * (len(citations) + 1)

        # Create counter for numbers with corresponding index
        for citation in citations:
            # Truncate numbers largers than n+1
            if citation >= len(citations):
                counter[len(citations)] += 1
            else:
                counter[citation] += 1

        total = 0
        for i in range(len(citations), 0, -1):
            total += counter[i]

            # Total cant be smaller than i, so return
            if i <= total:
                return i

        return 0

    def solution2(self, citations: List[int]) -> int:
        if len(citations) == 0:
            return 0
        
        h = len(citations)
        citations.sort(reverse=True)

        # print(citations)
        i = 0
        while i < len(citations):
            # print(citations[i])
            if i >= h:
                return h

            if citations[i] >= h:
                i += 1
            else:
                h -= 1

        return h
