class MinStack:

    def __init__(self):
        self._data = []
        self._min = 2 ** 31

    def push(self, val: int) -> None:
        if (val <= self._min):
            self._data.append(self._min)
            self._min = val
        self._data.append(val)

    def pop(self) -> None:
        if (self._min == self._data.pop()):
            self._min = self._data.pop()

    def top(self) -> int:
        return self._data[-1]

    def getMin(self) -> int:
        return self._min
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()