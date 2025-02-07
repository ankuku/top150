from typing import List

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        """
        There are N gas stations along a circular route where the amount of gas at station i is gas[i].
        You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to
        its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
        
        Given two integer arrays gas and cost, return the starting gas station's index if you can travel
        around the circuit once, otherwise return -1. You can only travel in one direction (i.e. no
        backtracking).
        
        You are given two integer arrays gas and cost, return the starting gas stations index if you can
        travel around the circuit once in a car with an unlimited gas tank, otherwise return -1.
        
        :param gas: The amount of gas in each station
        :type gas: List[int]
        :param cost: The cost of gas in each station
        :type cost: List[int]
        :return: The index of the starting station if the car can travel around the circuit once, otherwise -1
        :rtype: int
        """
        gas_left = 0
        start_station = 0

        if sum(gas) < sum(cost):
            return -1
        else:
            for i in range(len(gas)):
                gas_left += gas[i] - cost[i]
                if gas_left < 0:
                    start_station = i + 1
                    gas_left = 0
            return start_station


if __name__ == "__main__":
    gas = [1, 2, 3, 4, 5]
    cost = [3, 4, 5, 1, 2]
    print(Solution().canCompleteCircuit(gas, cost))