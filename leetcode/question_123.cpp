#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    
    typedef vector<int>::const_iterator iter;
    
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
            
        int ans = maxProfitOnce(prices.begin(), prices.end());
        
        for (iter i = prices.begin(); i != prices.end(); i++) {
            if ((i + 1) < prices.end() && *(i + 1) > *i)
                continue;
                
            int left = maxProfitOnce(prices.begin(), i + 1);
            if (left <= 0)
                continue;
                
            int right = maxProfitOnce(i + 1, prices.end());
            int two = left + right;

            if (two > ans)
                ans = two;
        }
        
        return ans;
    }

    int maxProfitOnce(iter begin, iter end) {
        if (begin == end)
            return 0;
            
        int max_sofar = 0;
        int max = 0;
        int p = *begin;
        for (iter i = begin; i != end; p = *i, i++) {
            max_sofar += *i - p;
            if (max_sofar < 0)
                max_sofar = 0;
            else if (max_sofar > max)
                max = max_sofar;
        }
        
        return max;
    }
};

int main() {
    Solution S;
    vector<int> prices = {2, 1, 2, 0, 1};
    cout << S.maxProfit(prices) << endl;

    return 0;
}
