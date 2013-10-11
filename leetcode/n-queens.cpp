#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/** The iterative solution using std::next_permutation()
 *
 * This can not pass when n == 8
 */
class Solution1 {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> numbers(n);
        for (int i = 0; i < n; i++)
            numbers[i] = i;
        
        vector<vector<string>> ans;
        do  {
            vector<bool> taken_left(2 * n , false);
            vector<bool> taken_right(2 * n , false);
            bool ok = true;
            vector<string> a;
            for (int row = 0; row < n; row++) {
                if (taken_left[n + numbers[row] - row] || taken_left[row + numbers[row]]) {
                    ok = false;
                    break;
                }
                string str(n, '.');
                str[numbers[row]] = 'Q';
                a.push_back(str);
                taken_left[n + numbers[row] - row] = true;
                taken_right[row + numbers[row]] = true;
            }
            if (ok)
                ans.push_back(a);
        } while (next_permutation(numbers.begin(), numbers.end()));
        
        return ans;
    }
};

/**
 * This solution permutes the colums by hand and prunes them once they
 * conflict. Thus this method is much more efficient than the first one.
 *
 * This solution passes the leetcode when n == 9
 */
class Solution2 {
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

/** In this approach, we check the candidate in constant time and prune them
 * as soon as possible
 *
 * This can pass the leetcode when n is up to 9
 */
class Solution3 {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n == 2 || n == 3)
            return ans;
            
        vector<bool> taken(n, false);
        vector<bool> taken_left(2 * n, false);
        vector<bool> taken_right(2 * n, false);
        vector<int> cols(n, -1);
        solveNQueens(ans, cols, taken, taken_left, taken_right, 0, n);
        
        return ans;
    }
    
    void solveNQueens(vector<vector<string>> &ans,
                      vector<int> &cols,
                      vector<bool> &taken,
                      vector<bool> &taken_left,
                      vector<bool> &taken_right,
                      int row,
                      int n) {
        // found one candidate
        if (row == n) {
            vector<string> a;
            for (int i = 0; i < n; i++) {
                string str(n, '.');
                str[cols[i]] = 'Q';
                a.push_back(str);
            }
            ans.push_back(a);
        } else {
            for (int col = 0; col < n; col++) {
                if (!taken[col] && !taken_right[row + col] && !taken_left[n + col - row]) {
                    taken[col] = true;
                    taken_right[row + col] = true;
                    taken_left[n + col - row] = true;
                    cols[row] = col;
                    solveNQueens(ans, cols, taken, taken_left, taken_right, row + 1, n);
                    
                    taken[col] = false;
                    taken_right[row + col] = false;
                    taken_left[n + col - row] = false;
                }
            }
        }
    }
};
