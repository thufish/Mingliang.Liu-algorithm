#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> s(S);
        sort(s.begin(), s.end());
        
        vector<vector<int> > answer;
        
        int n = s.size();
        long count = (long)pow(2, n);
        for (long i = 0; i < count; ++i) {
            vector<int> v;
            int k = i;
            int j = 0;
            do {
                if (k % 2)
                    v.push_back(s[j]);
                j++;
                k /= 2;
            } while (k);
            answer.push_back(v);
        }
        
        return answer;
    }
};
