class Solution {
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
