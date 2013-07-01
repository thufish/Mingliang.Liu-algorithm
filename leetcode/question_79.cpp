class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (word.size() == 0)
            return true;

        vector<vector<bool>> visited;
        for (int i = 0; i < board.size(); ++i)
            visited.push_back(vector<bool>(board[i].size(), false));
        
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j) {
                visited[i][j] = true;
                if(board[i][j] == word[0] && dfs(board, visited, i, j, word, 1))
                    return true;
                visited[i][j] = false;
            }

        return false;
    }
    
    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j, string word, int start) {
        // trivial cases first
        if (start == word.size())
            return true;
        
        // up
        if (i > 0 && !visited[i - 1][j] && board[i - 1][j] == word[start]) {
            if (start == word.size() - 1)
                return true;
                
            visited[i - 1][j] = true;
            if (dfs(board, visited, i - 1, j, word, start + 1))
                return true;
            visited[i - 1][j] = false;
        }
        // down
        if (i < board.size() - 1 && !visited[i + 1][j] && board[i + 1][j] == word[start]) {
            if (start == word.size() - 1)
                return true;
                
            visited[i + 1][j] = true;
            if (dfs(board, visited, i + 1, j, word, start + 1))
                return true;
            visited[i + 1][j] = false;
        }
        // left
        if (j > 0 && !visited[i][j - 1] && board[i][j - 1] == word[start]) {
            if (start == word.size() - 1)
                return true;
                
            visited[i][j - 1] = true;
            if (dfs(board, visited, i, j - 1, word, start + 1))
                return true;
            visited[i][j - 1] = false;
        }
        // right
        if (j < board[i].size() - 1 && !visited[i][j + 1] && board[i][j + 1] == word[start]) {
            if (start == word.size() - 1)
                return true;
                
            visited[i][j + 1] = true;
            if (dfs(board, visited, i, j + 1, word, start + 1))
                return true;
            visited[i][j + 1] = false;
        }
        
        return false;
    }
};
