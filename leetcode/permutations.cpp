class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> ans;
        vector<int> a;
        vector<bool> visited(num.size(), false);
        permuteHelper(num, visited, a, ans);
        return ans;
    }
    
    void permuteHelper(vector<int> &num, vector<bool> &visited, vector<int> a, vector<vector<int>> &ans) {
        if (a.size() == num.size()) {
            ans.push_back(a);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            if (visited[i])
                continue;

            a.push_back(num[i]);
            visited[i] = true;
            permuteHelper(num, visited, a, ans);
            a.pop_back();
            visited[i] = false;
        }
    }
};

/** Cheating
 */
class Solution2 {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> ans;
        sort(num.begin(), num.end());
        do {
            ans.push_back(vector<int>(num.begin(), num.end()));    
        } while (next_permutation(num.begin(), num.end()));
        
        return ans;
    }
};
