class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        int n = board.size();
        int rootn = sqrt(n);
        
        vector<vector<bool>> row_taken(n, vector<bool>(n + 1, false));
        vector<vector<bool>> col_taken(n, vector<bool>(n + 1, false));
        vector<vector<bool>> square_taken(n, vector<bool>(n + 1, false));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row_taken[i][num] = true;
                    col_taken[j][num] = true;
                    int square = i / rootn * rootn + j / rootn;
                    square_taken[square][num] = true;
                }
        
        solveSudoKuHelper(board, row_taken, col_taken, square_taken, 0);
    }
    
    bool solveSudoKuHelper(vector<vector<char>> &board,
                           vector<vector<bool>> &row_taken,
                           vector<vector<bool>> &col_taken,
                           vector<vector<bool>> &square_taken,
                           int index) {
        int n = board.size();
        if (index == n * n)
            return true;
            
        int row = index / n;
        int col = index % n;
        if (board[row][col] != '.')
            return solveSudoKuHelper(board, row_taken, col_taken, square_taken, index + 1);

        int rootn = sqrt(n);
        int square = row / rootn * rootn + col / rootn;
        for (int i = 1; i <= n; i++) {
            if (!row_taken[row][i] && !col_taken[col][i] && !square_taken[square][i]) {
                row_taken[row][i] = true;
                col_taken[col][i] = true;
                square_taken[square][i] = true;
                board[row][col] = i + '0';
                if (solveSudoKuHelper(board, row_taken, col_taken, square_taken, index + 1))
                    return true;
                row_taken[row][i] = false;
                col_taken[col][i] = false;
                square_taken[square][i] = false;
                board[row][col] = '.';
            }
        }
        
        return false;
    }
};
