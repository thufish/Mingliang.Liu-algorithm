#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/** A recursive version.
 * The main idea is to add the duplicate elements for different times
 */
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
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
        
        size_t count = 1;
        while (index + 1 < S.size() && S[index + 1] == S[index]) {
            index++;
            count++;
        }
        for (int i = 0; i <= count; i++) {
            // Add S[index] j times
            vector<int> subset2(subset);
            for (int j = 0; j < i; j++)
                subset2.push_back(S[index]);
            subsetsRecursive(subsets, S, subset2, index + 1);
        }
    }
};

int main() {
    vector<int> numbers = {1, 2, 2};
    Solution S;
    vector<vector<int>> subsets = S.subsetsWithDup(numbers);
    for (vector<int> s : subsets) {
        cout << "[";
        for (int i : s)
            cout << i << ",";
        cout << "]" << endl;
    }
    return 0;
}
