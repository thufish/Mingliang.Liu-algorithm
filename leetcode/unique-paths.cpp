class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> solutions(n, 1);

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                solutions[j] += solutions[j - 1];
        
        return solutions[n - 1];
    }
};
