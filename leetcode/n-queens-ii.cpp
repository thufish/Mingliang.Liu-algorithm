#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/** This is a non-recursive implementation of the NQueens problem.
 *
 * However, it fails because the next_permutation is slow. We can further
 * improve it by permuting the cases by ourselves.
 *
 * This solution can not pass the leetcode online judge for n == 10
 */
class Solution1 {
public:
    int totalNQueens(int n) {
        if (n == 1)
            return 1;
        else if (n == 2 || n == 3)
            return 0;
        
        vector<int> elements;
        for (int i = 0; i <n; i++)
            elements.push_back(i);
        int sum = 0;
        do {
            bool ok = true;
            vector<bool> taken_left(2 * n, false);
            vector<bool> taken_right(2 * n, false);
            for (int i = 0; i < n; i++) {
                if (taken_right[elements[i] + i] || taken_left[n + elements[i] - i]) {
                    ok = false;
                    break;
                }
                taken_right[elements[i] + i] = true;
                taken_left[n + elements[i] - i] = true;
            }
            if (ok)
                sum++;
        } while (next_permutation(elements.begin(), elements.end()));
        
        return sum;
    }
};

/**
 * We permute the colums by hand and prunes it if check() fails.
 * This solution is recursive with an extran auxiliary space (taken).
 *
 * However, this makes the time limit exceeded for n == 12.
 */
class Solution2 {
public:
    int totalNQueens(int n) {
        if (n == 1)
            return 1;
        else if (n == 2 || n == 3)
            return 0;
        else {
            vector<bool> taken(n, false);
            vector<int> cols(n, -1);
            return totalNQueens(cols, taken, 0, n);
        }
    }
    
    int totalNQueens(vector<int> cols, vector<bool> taken, int row, int n) {
        if (row == n)
            return 1;
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (!taken[i] && check(cols, row, i)) {
                cols[row] = i;
                taken[i] = true;
                sum += totalNQueens(cols, taken, row + 1, n);

                taken[i] = false;
            }
        }
        
        return sum;
    }
    
    bool check(vector<int> cols, int row, int col) {
        for (int i = 0; i < row; i++)
            if (cols[i] + i == row + col || i - cols[i] == row - col)
                return false;

        return true;
    }
};

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<bool> col(n, true);
        vector<bool> dia(2 * n, true);
        vector<bool> vdia(2 * n, true);
        totalNQueensHelper(n, 0, col, dia, vdia, ans);
        return ans;
    }
    
    void totalNQueensHelper(int n, int curr, vector<bool> &col, vector<bool> &dia, vector<bool> &vdia, int &ans) {
        if (curr == n) {
            ans++;
        } else {
            for (int i = 0; i < n; i++)
                if (col[i] && dia[i + curr] && vdia[i - curr + n]) {
                    col[i] = dia[i + curr] = vdia[i - curr + n] = false;
                    totalNQueensHelper(n, curr + 1, col, dia, vdia, ans);
                    col[i] = dia[i + curr] = vdia[i - curr + n] = true;
                }
        }
    }
};
