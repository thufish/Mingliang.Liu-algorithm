#include <vector>
#include <algorithm>

using namespace std;

/** Cheating
 */
class Solution1 {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        do {
            ans.push_back(vector<int>(num.begin(), num.end()));    
        } while (next_permutation(num.begin(), num.end()));
        
        return ans;
    }
};

/* I gave this answer to Li Zhuang when I was interviewed at MSRA.
 * She said it's not correct. She was wrong.
 */
class Solution2 {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > ans;
        permuteHelper(num, 0, ans);
        return ans;
    }
    
    void permuteHelper(vector<int> num, int index, vector<vector<int> > &ans) {
        if (index == num.size()) {
            ans.push_back(num);
        } else for (int i = index; i < num.size(); i++) {
            swap(num[i], num[index]);
            permuteHelper(num, index + 1, ans);
        }
    }
};
