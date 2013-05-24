#include <algorithm>
#include <vector>

using namespace std;

/** A very naive solution using library function std::next_permutation
 *
 * Actually we can't take this as a solution.
 * It's kind of cheeting :-)
 */
class Solution1 {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        
        vector<vector<int>> ans;
        do {
            vector<int> v(num.begin(), num.end());
            ans.push_back(v);
        } while (next_permutation(num.begin(), num.end()));
        
        return ans;
    }
};

/** This is a recursive version
 */
class Solution2 {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> ans;
            
        vector<bool> taken(num.size(), false);
        vector<int> per(num.size());
        permute(ans, per, taken, num, 0);
        
        return ans;
    }
    
    void permute(vector<vector<int>> &ans, vector<int> per, vector<bool> &taken,
                 vector<int> &num, int index) {
        if (index == num.size())
            ans.push_back(per);    
        else {
            for (int i = 0; i < num.size(); i++)
                if (!taken[i]) {
                    taken[i] = true;
                    per[i] = num[index];
                    permute(ans, per, taken, num, index + 1);
                    taken[i] = false;
                }
        }
    }
};
