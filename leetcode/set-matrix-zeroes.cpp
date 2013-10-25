class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if (m == 0)
            return;
        int n = matrix[0].size();
        
        bool firstRowHasZero = false;
        for (int i = 0; !firstRowHasZero && i < n; i++)
            if (!matrix[0][i])
                firstRowHasZero = true;
        
        bool firstColHasZero = false;
        for (int i = 0; !firstColHasZero && i < m; i++)
            if (!matrix[i][0])
                firstColHasZero = true;
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
        
        for (int i = 1; i < m; i++)
            if (!matrix[i][0])
                for (int j = 0; j < n; j++)
                    matrix[i][j] = 0;
        
        for (int i = 1; i < n; i++)
            if (!matrix[0][i])
                for (int j = 0; j < m; j++)
                    matrix[j][i] = 0;
        
        if (firstColHasZero)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        
        if (firstRowHasZero)
            for (int i = 0; i < n; i++)
                matrix[0][i] = 0;
    }
};
