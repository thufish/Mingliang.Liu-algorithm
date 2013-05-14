class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
            
        vector<int> diffs;
        
        int p = prices[0];
        for (auto i = prices.begin(); i != prices.end(); i++) {
            diffs.push_back(*i - p);
            p = *i;
        }
        
        int max = 0;
        int max_sofar = 0;
        for (auto i = diffs.begin(); i != diffs.end(); i++) {
            max_sofar += *i;
            if (max_sofar < 0)
                max_sofar = 0;
                
            if (max_sofar > max)
                max = max_sofar;
        }
        
        return max;
    }
};
