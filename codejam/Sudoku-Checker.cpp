#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <set>
#include <climits>

using namespace std;

bool solve() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n * n, vector<int>(n * n, 0));
    for (int i = 0; i < n * n; i++)
        for (int j = 0; j < n * n; j++)
            cin >> matrix[i][j];

    bool ok = true;

    for (int i = 0; i < n * n; i++) {
        vector<bool> row(n * n + 1, false);
        for (int j = 0; j < n * n; j++) {
            if (matrix[i][j] > (n * n) || row[matrix[i][j]]) {
                ok = false;
                break;
            }
            row[matrix[i][j]] = true;
        }
    }
    if (!ok)
        return false;

    for (int i = 0; i < n * n; i++) {
        vector<bool> col(n * n + 1, false);
        for (int j = 0; j < n * n; j++) {
            if (matrix[j][i] > (n * n) || col[matrix[i][j]]) {
                ok = false;
                break;
            }
            col[matrix[i][j]] = true;
        }
    }
    if (!ok)
        return false;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            vector<bool> square(n * n + 1, false);
            for (int k = 0; k < n; k++)
                for (int m = 0; m < n; m++) {
                    int row = i * n + k;
                    int col = j * n + m;
                    if (matrix[row][col] > (n * n) || square[matrix[row][col]])
                        return false;
                    square[matrix[row][col]] = true;
                }
        }

    return true;
}

int main() {
	ios::sync_with_stdio(false);
	int t,i;
	cin>>t;
	for(i=1;i<=t;++i){
		cout<<"Case #"<<i<<": ";
		cout << (solve() ? "Yes" : "No") << endl;
	}
}
