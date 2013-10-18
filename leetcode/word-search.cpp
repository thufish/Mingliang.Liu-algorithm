class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty() || board[0].empty())
            return false;
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (existHelper(board, word, 1, i, j, visited))
                        return true;
                    visited[i][j] = false;
                }
        
        return false;
    }
    
    bool existHelper(vector<vector<char>> &board, const string &word, int index, int i, int j, vector<vector<bool>> &visited) {
        if(index == word.length())
            return true;
        else {
            vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
            for (auto d : directions) {
                int row = i + d.first, col = j + d.second;
                if (row >= board.size() || row < 0 || col >= board[0].size() || col < 0)
                    continue;
                if (board[row][col] == word[index] && !visited[row][col]) {
                    visited[row][col] = true;
                    if (existHelper(board, word, index + 1, row, col, visited))
                        return true;
                    visited[row][col] = false;
                }
            }
            return false;
        }
    }
};
