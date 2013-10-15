class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int n = sqrt(board.size());
        
        // row
        for (int i = 0; i < board.size(); i++) {
            vector<bool> taken(board.size() + 1, false);
            for (int j = 0; j < board.size(); j++) {
                int num = (board[i][j] == '.' ? 0 : board[i][j] - '0');
                if (num && taken[num])
                    return false;
                else
                    taken[num] = true;
            }
        }
        
        // col
        for (int i = 0; i < board.size(); i++) {
            vector<bool> taken(board.size() + 1, false);
            for (int j = 0; j < board.size(); j++) {
                int num = (board[j][i] == '.' ? 0 : board[j][i] - '0');
                if (num && taken[num])
                    return false;
                else
                    taken[num] = true;
            }
        }
        
        // square       
        for(int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                vector<bool> taken(n + 1, false);
                for (int ii = 0; ii < n; ii++)
                    for (int jj = 0; jj < n; jj++) {
                        char c = board[i * n + ii][j * n + jj];
                        int num = (c == '.' ? 0 : c - '0');
                        if (num && taken[num])
                            return false;
                        else
                            taken[num] = true;
                    }
            }

        return true;
    }
};
