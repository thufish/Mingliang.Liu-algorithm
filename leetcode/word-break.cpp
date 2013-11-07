class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<bool>> contains(s.length(), vector<bool>(s.length(), false));
        for (int i = 0; i < s.length(); i++)
            for (int j = i; j < s.length(); j++)
                contains[i][j] = dict.count(s.substr(i, j - i + 1));
        
        vector<bool> f(s.length(), false);
        for (int i = 0; i < s.length(); i++) {
            f[i] = contains[0][i];
            for (int k = 0; !f[i] && k < i; k++)
                f[i] = f[k] && contains[k+1][i];
        }
        
        return f.back();
    }
};
