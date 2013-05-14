class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
         
        int max = 0;
        int max_sofar = 0;           
        int p = prices[0];
        for (auto i = prices.begin(); i != prices.end(); p = *i, i++) {
            max_sofar += *i - p;
            if (max_sofar < 0)
                max_sofar = 0;
            else if (max_sofar > max)
                max = max_sofar;
        }
        
        return max;
    }
};
