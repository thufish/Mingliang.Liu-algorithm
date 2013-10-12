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

void solve(){
    int B;
    cin >> B;
    vector<pair<long long, long long>> nodes;
    for (int b = 0; b < B; b++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (long long i = x1; i <= x2; i++)
            for (long long j = y1; j <= y2; j++)
                nodes.push_back({i, j});
    }

    long long ret = -1;
    long long x, y;
    for (auto n : nodes) {
        long long sum = 0;
        for (auto m : nodes)
            sum += abs(m.first - n.first) + abs(m.second - n.second);
        if (ret == -1 || sum < ret || sum == ret && n.first < x || sum == ret && n.first == x && n.second < y) {
            ret = sum;
            x = n.first;
            y = n.second;
        }
    }
    cout << x << " " << y << " " << ret << endl;
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
