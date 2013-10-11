class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        for (int l = 0; l < matrix.size() / 2; l++)
            for (int i = l; i < matrix.size() - 1 - l; i++) {
                int temp = matrix[l][i];
                matrix[l][i] = matrix[matrix.size() - 1 - i][l];
                matrix[matrix.size() - 1 - i][l] = matrix[matrix.size() - 1 - l][matrix.size() - 1 - i];
                matrix[matrix.size() - 1 - l][matrix.size() - 1 - i] = matrix[i][matrix.size() - 1 - l];
                matrix[i][matrix.size() - 1 - l] = temp;
            }
    }
};
