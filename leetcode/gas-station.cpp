#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int tank = 0, sum = 0, pos = 0;
        for(int i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (tank < 0) {
                tank = 0;
                pos = i + 1;
            }
        }

        return sum < 0 ? -1 : pos;
    }
};

int main() {
    Solution S;

    vector<int> gas = {1, 4, 1, 2, 2};
    vector<int> cost = {5, 1, 2, 1, 1};
    cout << S.canCompleteCircuit(gas, cost);

    vector<int> gas2 = {3, 1, 1};
    vector<int> cost2 = {1, 4, 2};
    cout << S.canCompleteCircuit(gas2, cost2);

    return 0;
}
