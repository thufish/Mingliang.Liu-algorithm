/** Cheating
 */
class Solution1 {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        set<vector<int>> ans;
        sort(num.begin(), num.end());
        do {
            ans.insert(vector<int>(num.begin(), num.end()));
        } while (next_permutation(num.begin(), num.end()));
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

/** Using the set like the first permute problem
 */
class Solution2 {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        set<vector<int>> ans;
        vector<bool> visited(num.size(), false);
        vector<int> a;
        permuteUniqueHelper(num, visited, a, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
    void permuteUniqueHelper(vector<int> &num, vector<bool> &visited, vector<int> a, set<vector<int>> &ans) {
        if (a.size() == num.size()) {
            ans.insert(a);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            if (visited[i])
                continue;
            a.push_back(num[i]);
            visited[i] = true;
            permuteUniqueHelper(num, visited, a, ans);
            visited[i] = false;
            a.pop_back();
        }
    }
};

/** The expected solution
 */
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        
        unordered_map<int, int> counts;
        for (int n : num)
            counts[n]++;
        
        vector<int> a(num.size(), 0);
        vector<vector<int>> ans;
        permuteUniqueHelper(num,  counts, a, 0, ans);
        return ans;
    }
    
    void permuteUniqueHelper(vector<int> &num, unordered_map<int, int> &counts, vector<int> a, int curr, vector<vector<int>> &ans) {
        if (curr == num.size())
            ans.push_back(a);
        else
            for (int i = 0; i < num.size(); i++)
                if (!i || num[i] != num[i - 1]) {
                    if (counts[num[i]] > 0) {
                        a[curr] = num[i];
                        counts[num[i]]--;
                        permuteUniqueHelper(num, counts, a, curr + 1, ans);
                        counts[num[i]]++;
                    }
                }
    }
};
