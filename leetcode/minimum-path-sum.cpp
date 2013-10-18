class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        vector<int> sums(grid[0].size(), INT_MAX);
        sums[0] = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++) {
                if (j > 0)
                    sums[j] = min(sums[j], sums[j - 1]);
                sums[j] += grid[i][j];
            }
        return sums.back();
    }
};
