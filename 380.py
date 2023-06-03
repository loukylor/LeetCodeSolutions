class RandomizedSet:

    def __init__(self):
        self._dict = {}
        self._list = []

    def insert(self, val: int) -> bool:
        contains = val in self._dict

        if contains:
            return False

        self._dict[val] = len(self._list)
        self._list.append(val)

        return True

    def remove(self, val: int) -> bool:
        contains = val in self._dict

        if not contains:
            return False

        # Swap values of last val in list with removed val
        old_idx = self._dict[val]
        self._dict[self._list[-1]] = old_idx
        self._list[old_idx] = self._list[-1]

        # Remove now useless last values
        idx = self._dict.pop(val)
        self._list.pop(-1)

        return True
        
    def getRandom(self) -> int:
        return random.choice(self._list)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
