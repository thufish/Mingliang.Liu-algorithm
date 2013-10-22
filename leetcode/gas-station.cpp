/** The O(N^2) solution which can not pass the large data set */
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        for (int j = 0; j < gas.size(); j++) {
            long long sum = 0;
            bool ok = true;
            for (int i = 0; ok && i < gas.size(); i++) {
                sum += gas[(i + j) % gas.size()] - cost[(i + j) % gas.size()];
                if (sum < 0)
                    ok = false;
            }
            if (ok)
                return j;
        }
        return -1;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() == 0)
            return -1;
        
        int sum = 0;
        int index = -1;
        bool last = true;
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            if (last && diff >= 0 && sum <= 0)
                index = i;
            last = (diff < 0);
            sum += diff;
        }
        
        if (index == -1)
            return index;
        
        for (int i = 0, sum = 0; i < gas.size(); i++) {
            sum += gas[(index + i) % gas.size()] - cost[(index + i) % gas.size()];
            if (sum < 0)
                return -1;
        }
        
        return index;
    }
};
