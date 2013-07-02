class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // trivial cases first
        if (obstacleGrid.empty())
            return 0;
        int n = obstacleGrid[0].size();
        if (n == 0 || obstacleGrid[0][0])
            return 0;

        vector<int> paths(n, 0);
        paths[0] = 1;
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            if (obstacleGrid[i][0])
                paths[0] = 0;
            for (int j = 1; j < n; ++j)
                if (!obstacleGrid[i][j])
                    paths[j] += paths[j - 1];
                else
                    paths[j] = 0;
        }
        
        return paths.back();
    }
};
