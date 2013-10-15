class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;

        for (int i = 0; i < matrix.size() / 2; i++) {
            // top
            for (int j = i; j < matrix[0].size() - i; j++)
                ans.push_back(matrix[i][j]);
            // right
            for (int j = i + 1; j < matrix.size() - i; j++)
                ans.push_back(matrix[j][i]);
            // bottom
            for (int j = matrix[0].size() - i - 2; j >= i; j--)
                ans.push_back(matrix[i][j]);
            // left
            for (int j = matrix.size() - i - 2; j > i; j--)
                ans.push_back(matrix[j][i]);
        }
        
        return ans;
    }
};
