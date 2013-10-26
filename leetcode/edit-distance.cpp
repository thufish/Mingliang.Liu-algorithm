class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        if (m == 0)
            return n;
        else if (n == 0)
            return m;

        vector<vector<int>> steps(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++)
            steps[i][0] = i;
        
        for (int j = 1; j <= n; j++)
            steps[0][j] = j;
        
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    steps[i][j] = steps[i - 1][j - 1];
                else
                    steps[i][j] = min3(steps[i - 1][j - 1], steps[i - 1][j], steps[i][j - 1]) + 1;
            }
        
        return steps.back().back();
    }
    
    inline int min3(const int a, const int b, const int c) {
        return min(a, min(b, c));
    }
};
