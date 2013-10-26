#include <algorithm>

/** The very naive solution which will not pass the large data size */
class Solution {
public:
    string getPermutation(int n, int k) {
        string str;
        for (int i = 1; i <= n; i++)
            str.push_back(i + '0');
        do {
            k--;
        } while (k && next_permutation(str.begin(), str.end()));
        
        return str;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        string dict;
        vector<int> factorial(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
            dict += i + '0';
        }
        
        string str;
        k--;
        for (int i = n - 1; i >= 0; i--) {
            int eff = k / factorial[i];
            str += dict[eff];
            dict.erase(eff, 1);
            k %= factorial[i];
        }

        return str;
    }
};
