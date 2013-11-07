class Solution {
public:
    void solve(vector<vector<char>> &board) {
        const int m = board.size();
        if (m < 3)
            return;
        const int n = board[0].size();
        if (n < 3)
            return;

        queue<pair<int, int>> Q;
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O')
                Q.push({0, i});
            if (board[m - 1][i] == 'O')
                Q.push({m - 1, i});
        }
        for (int i = 1; i < m - 1; i++) {
            if (board[i][0] == 'O')
                Q.push({i, 0});
            if (board[i][n - 1] == 'O')
                Q.push({i, n - 1});
        }
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!Q.empty()) {
            pair<int, int> p = Q.front();
            Q.pop();
            board[p.first][p.second] = 'o';
            for (auto d : directions) {
                int i = p.first + d.first;
                int j = p.second + d.second;
                if (i < 0 || i >= m || j < 0 || j >= n)
                    continue;
                if (board[i][j] == 'O')
                    Q.push({i, j});
            }
        }
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = (board[i][j] == 'o' ? 'O' : 'X');
    }
};
