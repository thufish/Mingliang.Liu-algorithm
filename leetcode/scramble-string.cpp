class Solution {
public:
    bool isScramble(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        if (m == 0 && n == 0)
            return true;
        else if (m != n)
            return false;
        
        vector<vector<vector<bool>>> dp(m + 1, vector<vector<bool>>(m, vector<bool>(m, false)));
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++) {
                dp[0][i][j] = true;
                dp[1][i][j] = s1[i] == s2[j];
            }
        
        for (int len = 1; len <= m; len++)
            for (int i = 0; i < m - len + 1; i++)
                for (int j = 0; j < m - len + 1; j++)
                    for (int k = 0; !dp[len][i][j] && k < len; k++)
                        dp[len][i][j] = (dp[k][i][j] && dp[len - k][i + k][j + k]) ||
                                        (dp[k][i][j + len - k] && dp[len - k][i + k][j]);
        
        return dp.back()[0][0];
    }
};
