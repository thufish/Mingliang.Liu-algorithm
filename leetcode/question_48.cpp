class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.size() == 0)
            return;
        int n = matrix.size();
        
        for (int l = 0; l < n / 2; ++l)
            for (int i = 0; i < n - 2 * l - 1; ++i) {
                int temp = matrix[l][l + i];
                // left -> top
                matrix[l][l + i] = matrix[n - 1 - l - i][l];
                // bottom -> left
                matrix[n - 1 - l - i][l] = matrix[n - 1 - l][n - 1 - l - i];
                // right -> bottom
                matrix[n - 1 - l][n - 1 - l - i] = matrix[l + i][n - 1 - l];
                // top -> right
                matrix[l + i][n - 1 - l] = temp;
            }
    }
};
