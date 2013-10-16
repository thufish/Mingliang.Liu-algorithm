#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        if (matrix.size() < 1)
            return ans;
        
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < min((m + 1) / 2, (n + 1) / 2); i++) {
            // top
            for (int j = i; j < n - i; j++)
                ans.push_back(matrix[i][j]);
            // right
            for (int j = i + 1; j < m - i; j++)
                ans.push_back(matrix[j][n - 1 - i]);
            // bottom
            for (int j = n - i - 2; m - 1 - i > i && j >= i; j--)
                ans.push_back(matrix[m - 1 - i][j]);
            // left
            for (int j = m - i - 2; n - 1 - i > i && j > i; j--)
                ans.push_back(matrix[j][i]);
        }
        
        return ans;
    }
};
