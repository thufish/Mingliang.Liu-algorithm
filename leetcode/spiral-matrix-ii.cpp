#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int number = 1;
        for (int level = 0; level < (n + 1) / 2; level++) {
            // top
            for (int i = level; i < n - level; i++)
                ans[level][i] = number++;
            // right
            for (int i = level + 1; i < n - level; i++)
                ans[i][n - 1 - level] = number++;
            // bottom
            for (int i = n - 2 - level; i >= level; i--)
                ans[n - 1 - level][i] = number++;
            // left
            for (int i = n - 2 - level; i > level; i--)
                ans[i][level] = number++;
        }
        
        assert(number == (n * n + 1));
        return ans;
    }
};
