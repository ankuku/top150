import random


class RandomizedSet:

    def __init__(self):
        self.map = {}
        self.arr = []

    def insert(self, val: int) -> bool:
        if val in self.map:
            return False
        
        self.arr.append(val)
        self.map[val] = len(self.arr) - 1
        return True
        

    def remove(self, val: int) -> bool:
        if val not in self.map:
            return False
        
        last_element = self.arr[-1]
        idx_of_val_to_remove = self.map[val]

        self.arr[idx_of_val_to_remove] = last_element
        self.map[last_element] = idx_of_val_to_remove

        self.arr.pop()
        del self.map[val]
        return True

    def getRandom(self) -> int:
        return random.choice(self.arr)


if __name__ == "__main__":
    obj = RandomizedSet()

    commands = ["RandomizedSet", "remove", "remove", "insert", "getRandom", "remove", "insert"]
    arguments = [[], [0], [0], [0], [], [0], [0]]

    # Simulate input
    for i, command in enumerate(commands):
        if command == "RandomizedSet":
            print("null")
        elif command == "insert":
            result = obj.insert(arguments[i][0])
            print(result)
        elif command == "remove":
            result = obj.remove(arguments[i][0])
            print(result)
        elif command == "getRandom":
            result = obj.getRandom()
            print(result)