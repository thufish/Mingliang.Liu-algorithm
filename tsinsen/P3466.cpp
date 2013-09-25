#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    int c = max(a, b);
    int d = min(a, b);

    int r = c % d;
    while (r > 0) {
        c = d;
        d = r;
        r = c % d;
    }

    return d;
}

int main() {
    vector<int> V;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        V.push_back(a);
    }

    while (true) {
        vector<int> M;
        for (int i = 0; i < V.size() - 1; i += 2)
            M.push_back(gcd(V[i], V[i + 1]));
        if (V.size() % 2)
            M.push_back(V.back());

        if (M.size() == 1) {
            cout << M[0] << endl;
            break;
        } else
            V = M;
    }

    return 0;
}
