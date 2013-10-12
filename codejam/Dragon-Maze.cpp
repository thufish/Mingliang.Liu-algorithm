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
#include <queue>

using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve(){

    int n, m;
    cin >> n >> m;

    // entry and the exit point
    int enx, eny, exx, exy;
    cin >> enx >> eny >> exx >> exy;

    // read the matrix
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> steps(n, vector<int>(m, 0));
    vector<vector<int>> energy(n, vector<int>(m, 0));
    
    queue<pair<int, int>> Q;
    Q.push({enx, eny});
    energy[enx][eny] = matrix[enx][eny];
    visited[enx][eny] = true;
    while (!Q.empty()) {
        pair<int, int> p = Q.front();
        Q.pop();
        
        for (auto d : directions) {
            int x = p.first + d.first;
            int y = p.second + d.second;
            if (x < 0 || x > n - 1 || y < 0 || y > m - 1)
                continue;

            if (matrix[x][y] > 0 && !visited[x][y]) {
                steps[x][y] = steps[p.first][p.second] + 1;
                visited[x][y] = true;
                for (auto dd : directions) {
                    int xx = x + dd.first;
                    int yy = y + dd.second;
                    if (xx < 0 || xx > n - 1 || yy < 0 || yy > m - 1)
                        continue;
                    if (visited[xx][yy] && (steps[xx][yy] == steps[x][y] - 1))
                        energy[x][y] = max(energy[xx][yy] + matrix[x][y], energy[x][y]);
                }

                if (x == exx && y == exy) {
                    cout << energy[x][y] << endl;
                    return;
                } else
                    Q.push({x, y});
            }
        }
    }
    cout << "Mission Impossible." << endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t,i;
	cin>>t;
	for(i=1;i<=t;++i){
		cout<<"Case #"<<i<<": ";
		solve();
	}
}
