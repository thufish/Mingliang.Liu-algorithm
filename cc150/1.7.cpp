#include <iostream>
#include <vector>

#define N 5

using namespace std;

void reset_zero(int matrix[N][N], int n) {
    vector<bool> rows(n, false);
    vector<bool> cols(n, false);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
        }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (rows[i] || cols[j])
                matrix[i][j] = 0;
}

void dump(int matrix[N][N], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

int main() {
    int matrix[N][N] = {{1, 2, 3, 0, 4}, {1, 0, 2, 3, 4}, {1, 2, 3, 4, 5}, {1, 2, 0, 3, 4}, {1, 2, 3, 4, 5}};
    dump(matrix, N);
    cout << endl;

    reset_zero(matrix, N);
    dump(matrix, N);

    return 0;
}
