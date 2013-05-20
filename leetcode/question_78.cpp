/** Given a set of distinct integers, S, return all possible subsets.
    Note:
    - Elements in a subset must be in non-descending order.
    - The solution set must not contain duplicate subsets.
*/

#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

/// This solution uses the bit vector to select the elements
/// For n numbers in S, there are 2^n bit vector elements; thus we should
/// select the number if the bit is 1 and ignore the number if the bit is 0
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
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

/// This solution uses the recursive method to select the elements
/// The final trick here is when to add the current answer (index == S.size())
class Solution2 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> subsets;
        if (S.size() == 0)
            return subsets;

        sort(S.begin(), S.end());
        vector<int> subset;
        subsetsRecursive(subsets, S, subset, 0);
        
        return subsets;
    }
    
    void subsetsRecursive(vector<vector<int>> &subsets, vector<int> &S, vector<int> subset, int index) {
        if (index == S.size()) {
            // Add the current answer
            sort(subset.begin(), subset.end());
            subsets.push_back(subset);
            return;
        }
        
        // Don't add S[index]
        subsetsRecursive(subsets, S, subset, index + 1);
        
        // Add S[index]
        subset.push_back(S[index]);
        subsetsRecursive(subsets, S, subset, index + 1);
    }
};
