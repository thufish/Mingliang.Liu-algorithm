class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        unordered_map<int, int> counts;
        for (int s : S)
            counts[s]++;
        sort(S.begin(), S.end());
        S.erase(unique(S.begin(), S.end()), S.end());
        vector<vector<int>> ans;
        vector<int> a;
        subsetsWithDupHelper(S, counts, a, 0, ans);
        return ans;
    }
    
    void subsetsWithDupHelper(vector<int> &S, unordered_map<int, int> &counts, vector<int> a, int index, vector<vector<int>> &ans) {
        if (index == S.size())
            ans.push_back(a);
        else for (int i = 0; i <= counts[S[index]]; i++) {
                subsetsWithDupHelper(S, counts, a, index + 1, ans);
                a.push_back(S[index]);
            }
    }
};
