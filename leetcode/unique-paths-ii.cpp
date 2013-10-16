class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;

        vector<int> paths(obstacleGrid[0].size(), 0);
        paths[0] = 1;
        for (int i = 0; i < obstacleGrid.size(); i++) {
            paths[0] = paths[0] && !obstacleGrid[i][0];
            for (int j = 1; j < obstacleGrid[0].size(); j++)
                paths[j] = (obstacleGrid[i][j] ? 0 : paths[j] + paths[j - 1]);
        }
        
        return paths[obstacleGrid[0].size() - 1];
    }
};
