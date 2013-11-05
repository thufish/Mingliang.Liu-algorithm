#include <iostream>

using namespace std;

void rotate_matrix(int matrix[][4], int n) {
    for (int l = 0; l < n / 2; ++l)
        for (int i = 0; i < n - 2 * l - 1; ++i) {
            int temp = matrix[l][l + i];
            // left -> top
            matrix[l][l + i] = matrix[n - 1 - l - i][l];
            // bottom -> left
            matrix[n - 1 - l - i][l] = matrix[n - 1 - l][n - 1 - l - i];
            // right -> bottom
            matrix[n - 1 - l][n - 1 - l - i] = matrix[l + i][n - 1 - l];
            // top -> right
            matrix[l + i][n - 1 - l] = temp;
        }
}

void dump(int matrix[][4], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

int main() {
    int matrix[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 2, 3}, {4, 5, 6, 7}};
    dump(matrix, 4);

    cout << endl;

    rotate_matrix(matrix, 4);
    dump(matrix, 4);

    return 0;
}
