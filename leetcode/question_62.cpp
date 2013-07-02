class Solution1 {
public:
    int uniquePaths(int m, int n) {
        vector<int> paths(n, 1);
        
        for (int i = 1; i < m; ++i) {
            vector<int> qaths(n, 1);
            for (int j = 1; j < n; ++j)
                qaths[j] = paths[j] + qaths[j - 1];
            paths = qaths;
        }
        
        return paths[n - 1];
    }
};

/** Actuall, only one array is needed here */
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                dp[j+1] = dp[j]+dp[j+1];
            }
        }
        return dp.back();
    }
};
