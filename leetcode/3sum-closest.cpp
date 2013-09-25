#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int diff = INT_MAX;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            int j = i, k = num.size() - 1;
            while (j < k) {
                if (i == j)
                    j++;
                else if (i == k)
                    k--;
                else {
                    int sum = num[i] + num[j] + num[k];
                    if (sum == target)
                        return target;
                    else if (sum < target)
                        j++;
                    else
                        k--;
                    if (abs(sum - target) < abs(diff))
                        diff = sum - target;
                }
            }
        }
        return target + diff;
    }
};
