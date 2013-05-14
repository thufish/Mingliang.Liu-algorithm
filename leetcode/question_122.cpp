class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
         
        int max = 0;
        int p = prices[0];
        for (auto i = prices.begin(); i != prices.end(); p = *i, i++) {
            int d = *i - p;
            if (d > 0)
                max += d;
        }
        
        return max;
    }
};
