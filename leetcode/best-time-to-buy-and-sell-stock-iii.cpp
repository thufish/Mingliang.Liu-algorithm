class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
            return 0;
        
        vector<int> once(prices.size(), 0);
        int min_p = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            once[i] = max(prices[i] - min_p, once[i - 1]);
            min_p = min(min_p, prices[i]);
        }
        
        int ret = 0;
        int max_p = prices.back();
        int from_here = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            from_here = max(max_p - prices[i], from_here);
            ret = max(ret, once[i] + from_here);
            max_p = max(max_p, prices[i]);
        }
        return ret;
    }
};

/** Dynamic Programming
 *
 * f[i][j] is the max sum of j segments ended with diff[i]
 * Thus:
 *              |- f[i - 1][j] + diff[i]                       # append diff[i] to j segments
 * f[i][j] = max|
 *              |- max{f[k][j - 1], k in [0, i - 1]} + diff[i] # new segment from diff[i]
 *
 * Store the max{...} in g[i - 1][j - 1], then we can access the max in O(1) time 
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int f[3] = {0};
        int g[3] = {0};

        int n = prices.size() - 1;
        for (int i = 0; i < n; ++i) {
            int diff = prices[i+1] - prices[i];
            int m = min(i+1, 2);
            for (int j = m; j >= 1; --j) {
                f[j] = max(f[j], g[j-1]) + diff;
                g[j] = max(g[j], f[j]);
            }
        }
        return max(g[1], g[2]);
    }
};
