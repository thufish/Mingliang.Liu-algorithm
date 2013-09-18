class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            ret += max(diff, 0);
        }
        
        return ret;
    }
};
