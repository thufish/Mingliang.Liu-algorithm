#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

/** This is a naive solution using std::next_permutation
 *
 * This is considered cheating.
 */
class Solution1 {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> ans;
        
        sort(num.begin(), num.end());
        do {
            vector<int> a(num.begin(), num.end());
            ans.push_back(a);
        } while (next_permutation(num.begin(), num.end()));
        
        return ans;
    }
};

/** The recursive solution to this question
 *
 * We use a start index and a counts map as two helper parameters
 *  - we only iterate the unique elements (index < un).
 *  - However, the position is from 0 to num.size()
 *  - For same elements, we use the start index to avoid the redundant
 */
class Solution2 {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> ans;
        if (num.size() == 0)
            return ans;
        
        map<int, int> counts;
        for (int i : num)
            counts[i]++;
            
        sort(num.begin(), num.end());
        int un = unique(num.begin(), num.end()) - num.begin();
        
        vector<int> per(num.size());
        vector<bool> taken(num.size(), false);
        permuteUnique(ans, per, taken, num, counts, 0, 0, un);
        
        return ans;
    }
    
    void permuteUnique(vector<vector<int>> &ans, vector<int> per, vector<bool> &taken,
                       vector<int> &num, map<int, int> &counts, int start, int index, int un) {
        if (index == un) { // found one per
            ans.push_back(per);
        } else {
            for (int i = start; i < num.size(); i++) {
                while (i < num.size() && taken[i])
                    i++;
                if (i == num.size())
                    break;
                per[i] = num[index];
                taken[i] = true;
                counts[num[index]]--;
                if (counts[num[index]] > 0) {
                    permuteUnique(ans, per, taken, num, counts, i + 1, index, un);
                } else {
                    permuteUnique(ans, per, taken, num, counts, 0, index + 1, un);
                }
                counts[num[index]]++;
                taken[i] = false;
            }
        }
    }
};

int main() {
    Solution2 S;
    vector<int> num = {1, 1, 2};
    vector<vector<int>> ans = S.permuteUnique(num);
    for (auto a : ans) {
        for (auto i : a)
            cout << i << "\t";
        cout << endl;
    }
    return 0;
}
