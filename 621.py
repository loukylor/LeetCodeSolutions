class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # Count how many tasks we encounter here
        counter = [0] * 26
        
        # Keep track of which index appears the most, and
        # how many indexes also appeared that many times
        max_ = 0
        maxes = 0

        for task in tasks:
            idx = ord(task) - ord("A")
            counter[idx] += 1
            if max_ < counter[idx]:
                max_ = counter[idx]
                maxes = 1
            elif max_ == counter[idx]:
                maxes += 1

        available_count = (max_ - 1) * (n - maxes + 1)
        unfulfilled_tasks = len(tasks) - (max_ * maxes)
        idle_count = max(0, available_count - unfulfilled_tasks)

        return len(tasks) + idle_count
