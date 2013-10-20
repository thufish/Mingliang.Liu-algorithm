#include <unordered_map>

/** The naive solution using hashing map holding range */
class Solution1 {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> range;
        int max_len = 1;
        
        for (int i = 0; i < num.size(); ++i) {
            if (range.find(num[i]) != range.end())
                continue;

            range[num[i]] = num[i];
            
            if (range.find(num[i] - 1) != range.end()) {
                int min = range[num[i] - 1];
                int max = num[i];
                range[num[i]] = min;
                range[range[num[i] - 1]] = max;
                if (max - min + 1 > max_len)
                    max_len = max - min + 1;
            }
            
            if (range.find(num[i] + 1) != range.end()) {
                int min = range[num[i]];
                int max = range[num[i] + 1];
                range[range[num[i] + 1]] = min;
                range[range[num[i]]] = max;
                if (max - min + 1 > max_len)
                    max_len = max - min + 1;
            }
        }
        
        return max_len;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, pair<int, int>> consec;
        int ret = 0;
        for (int n : num) {
            if (consec.find(n) != consec.end())
                continue;
            consec[n] = {n, n};
            pair<int, int> p = {n, n}, q = {n, n};
            if (consec.find(n - 1) != consec.end())
                p = consec[n - 1];
            if (consec.find(n + 1) != consec.end())
                q = consec[n + 1];
            consec[q.second] = {p.first, q.second};
            consec[p.first] = {p.first, q.second};
            ret = max(ret, q.second - p.first + 1);
        }
        return ret;
    }
};
