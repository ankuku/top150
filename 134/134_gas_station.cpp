#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current_gas = 0;
        int total_gas = 0;
        int start_station = 0;
        int total_cost = 0;

        for (int i = 0; i < gas.size(); i++) {      
            total_gas += gas[i];
            total_cost += cost[i];
            current_gas += gas[i] - cost[i];

            if (current_gas < 0) {
                current_gas = 0;
                start_station = i + 1;
            }
        }
        return total_gas >= total_cost ? start_station : -1;
    }
};


int main() {
    Solution sol;

    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    cout << sol.canCompleteCircuit(gas, cost) << endl;
    
    return 0;
}