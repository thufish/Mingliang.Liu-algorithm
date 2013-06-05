#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/** The Devide-and-Conquer solution
 *
 * T(N) = 2 * T(N / 2) + O(N)
 *
 * Thus the O(NlgN) totally
 */
class Solution1 {
public:
    int maxProfit(vector<int> &prices) {
        return maxProfitRecursive(prices, 0, prices.size() - 1); 
    }

    int maxProfitRecursive(const vector<int> &prices, int start, int end) {
        if (start >= end)
            return 0;
        if (end - start == 1)
            return max(0, prices[end] - prices[start]);

        int mid = start + (end - start) / 2; // here we should note how to calculate the mid
        int max_left = maxProfitRecursive(prices, start, mid);
        int max_right = maxProfitRecursive(prices, mid + 1, end); 

        int mid_max_left = 0;
        int mid_curr = 0;
        for (int i = mid; i > start; --i) { // from mid to start!
            mid_curr += prices[i] - prices[i - 1];
            if (mid_curr > mid_max_left)
                mid_max_left = mid_curr;
        }

        int mid_max_right = 0;
        mid_curr = 0;
        for (int i = mid + 1; i <= end; ++i) { // from mid to end!
            mid_curr += prices[i] - prices[i - 1];
            if (mid_curr > mid_max_right)
                mid_max_right = mid_curr;
        }

        return max(max(max_left, max_right), mid_max_left + mid_max_right);
    }
};

/** The dynamic program solution in O(N) time
 *
 *  Let f(n) be the maxium profit ending at diff[n], then
 *  f(n) = max(0, f(n - 1) + diff[n]
 */
class Solution2 {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
         
        int max_sofar = 0;
        int max_endinghere = 0;           
        int p = prices[0];
        for (auto i = prices.begin(); i != prices.end(); p = *i, i++) {
            max_endinghere += *i - p;
            if (max_endinghere < 0)
                max_endinghere = 0;
            else if (max_endinghere > max_sofar)
                max_sofar = max_endinghere;
        }
        
        return max_sofar;
    }
};

int main() {
    Solution S1;
    vector<int> v = {3,2,6,5,0,3};
    cout << S1.maxProfit(v);
    return 0;
}
