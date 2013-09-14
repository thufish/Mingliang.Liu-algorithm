#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

enum COLOR {
    WHITE,
    RED,
    BLUE
};

static void troublesome(vector<vector<int>> &adj) {
    vector<COLOR> color(adj.size(), WHITE);
    for (int node = 0; node < adj.size(); ++node) {
        if (color[node] != WHITE)
            continue;

        queue<int> Q;
        Q.push(0);
        color[0] = RED;
        while (!Q.empty()) {
            int n = Q.front();
            Q.pop();
            COLOR c = (color[n] == RED) ? BLUE : RED;
            for (int i = 0; i < adj[n].size(); ++i)
                if (color[adj[n][i]] == WHITE) {
                    color[adj[n][i]] = c;
                    Q.push(adj[n][i]);
                } else if (color[adj[n][i]] != c) {
                    cout << "No";
                    return;
                }
        }
    }
    cout << "Yes";
}

int main() {
    int T;
    cin >> T;
    for (int c = 1; c <= T; ++c) {
        int M;
        cin >> M;

        int node_num = 0;
        vector<vector<int>> adj(2 * M, vector<int>());
        unordered_map<string, int> nodes;

        for (int i = 0; i < M; ++i) {
            string s1, s2;
            cin >> s1 >> s2;
            int n1 = nodes.count(s1) ? nodes[s1] : node_num++;
            nodes[s1] = n1;
            int n2 = nodes.count(s2) ? nodes[s2] : node_num++;
            nodes[s2] = n2;
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
        cout << "Case #" << c << ": ";
        adj.resize(node_num);
        troublesome(adj);
        cout << endl;
    }

    return 0;
}
