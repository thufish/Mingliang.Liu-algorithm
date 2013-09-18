#include <algorithm>
#include <vector>

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;

        int min_p = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            ans = max(ans, prices[i] - min_p);
            min_p = min(min_p, prices[i]);
        }

        return ans;
    }
};
