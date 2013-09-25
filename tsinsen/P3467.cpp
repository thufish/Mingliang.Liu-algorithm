#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

enum HAND {
    JIANDAO = 0,
    SHITOU = 1,
    BU = 2,
    UNKNOWN
};
HAND hands[] = {JIANDAO, SHITOU, BU};

enum HINT {
    WIN = 0,
    LOSE = 1,
    DEAL = 2
};

int dfs(vector<vector<pair<int, HINT>>> &H);
bool dfs_impl(vector<vector<pair<int, HINT>>> &H, vector<HAND> &h, int from);

int N, M;

int main() {
    cin >> N >> M;

    vector<vector<pair<int, HINT>>> H(N);
    
    for (int m = 0; m < M; m++) {
        char c;
        int i, j;
        cin >> c >> i >> j;
        if (c == 'W') {
            H[i - 1].push_back({j - 1, WIN});
            H[j - 1].push_back({i - 1, LOSE});
        } else {
            H[i - 1].push_back({j - 1, DEAL});
            H[j - 1].push_back({i - 1, DEAL});
        }
    }

    cout << dfs(H) << endl;

    return 0;
}

int dfs(vector<vector<pair<int, HINT>>> &H) {
    vector<HAND> h(N, UNKNOWN);
    int ret = 1;
    for (int i = 0; i < H.size(); i++)
        if (h[i] == UNKNOWN) {
            h[i] = JIANDAO;
            if (dfs_impl(H, h, i))
                ret = (ret * 3) % 10007;
            else
                return 0;
        }

    return ret;
}

bool dfs_impl(vector<vector<pair<int, HINT>>> &H, vector<HAND> &h, int from) {
    assert(h[from] != UNKNOWN);
    for (int j = 0; j < H[from].size(); j++) {
        HAND e;
        if (H[from][j].second == DEAL)
            e = h[from];
        else if (H[from][j].second == LOSE)
            e = hands[(h[from] + 1) % 3];
        else
            e = hands[(h[from] + 2) % 3];

        if (h[H[from][j].first] == UNKNOWN) {
            h[H[from][j].first] = e;
            if (!dfs_impl(H, h, H[from][j].first))
                return false;
        } else if (h[H[from][j].first] != e)
            return false;
    }

    return true;
}
