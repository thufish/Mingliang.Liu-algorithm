#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/** Dynamic programming
 *
 * f[i][j] is the max sum of j segments ended with diff[i]
 * Thus:
 * f[i][j] = |- f[i - 1][j] + diff[i]                       # append diff[i] to j segments
 *           |- max{f[k][j - 1], k in [0, i - 1]} + diff[i] # new segment from diff[i]
 *
 * Store the max{...} in g[], then we can access the max in O(1) time 
 */
class Solution {
public:
    
    typedef vector<int>::const_iterator iter;
    
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2)
            return 0;

        int f[3] = {0};
        int g[3] = {0};

        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            int m = min(i, 2);
            for (int j = m; j >= 1; --j) {
                f[j] = max(f[j], g[j - 1]) + diff;
                g[j] = max(g[j], f[j]);
            }
        }
            
        return max(g[1], g[2]);
    }
};

int main() {
    Solution S;
    vector<int> prices = {2, 1, 2, 0, 1};
    cout << S.maxProfit(prices) << endl;

    return 0;
}
