#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n == 2 || n == 3)
            return ans;
        
        vector<bool> cols_taken(n, false);
        vector<int> cols(n, -1);
        solveNQueens(ans, cols, cols_taken, 0, n);

        return ans;
    }
    
    void solveNQueens(vector<vector<string>> &ans, vector<int> cols, vector<bool> cols_taken, int row, int n) {
        if (row == n) {
            vector<string> a;
            for (int i = 0; i < row; i++) {
                string str(n, '.');
                str[cols[i]] = 'Q';
                a.push_back(str);
            }
            ans.push_back(a);
        } else {
            for (int col = 0; col < n; col++) {
                if (!cols_taken[col] && check(cols, row, col)) {
                    cols_taken[col] = true;
                    cols[row] = col;
                    solveNQueens(ans, cols, cols_taken, row + 1, n);

                    cols_taken[col] = false;
                    cols[row] = -1;
                }
            }
        }
    }
    
    bool check(vector<int> cols, int row, int col) {
        bool ok = true;
        for (int i = 0; i < row; i++) {
            if (cols[i] + i == row + col)
                ok = false;
            else if (i - cols[i] == row - col)
                ok = false;
        }
        
        return ok;
    }
};

int main() {
    Solution S;
    auto ans = S.solveNQueens(1);
    return 0;
}
