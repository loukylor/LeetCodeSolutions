class TimeMap:

    def __init__(self):
        self.data = {}
        

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.data:
            self.data[key] = [(timestamp, value)]
        else:
            self.data[key].append((timestamp, value))
        

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.data:
            return ""
        entries = self.data[key]

        l = 0
        r = len(entries) - 1
        res = ""
        while l <= r:
            m = l + ((r - l) // 2)
            if entries[m][0] <= timestamp:
                l = m + 1
                res = entries[m][1]
            else:
                r = m - 1
        
        return res


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)