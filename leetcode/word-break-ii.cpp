class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.length() + 1, false);
        vector<vector<bool>> path(s.length() + 1, vector<bool>(s.length(), false));
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++)
            for (int j = i - 1; j >= 0; j--)
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    path[i][j] = true;
                }
        
        vector<string> ret;
        vector<string> sen;
        genPath(s, s.length(), path, ret, sen);
        
        return ret;
    }
    
    void genPath(string &s, int index, const vector<vector<bool>> &path, vector<string> &ret, vector<string> sen) {
        if (index == 0) {
            string st;
            for (auto i = sen.rbegin(); i != sen.rend(); i++)
                st += *i + " ";
            st.pop_back();
            ret.push_back(st);
        } else {
            for (int i = 0; i < index; i++)
                if (path[index][i]) {
                    sen.push_back(s.substr(i, index - i));
                    genPath(s, i, path, ret, sen);
                    sen.pop_back();
                }
        }
    }
};
