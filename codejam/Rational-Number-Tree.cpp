#include <string>
#include <iostream>

using namespace std;

pair<unsigned long long, unsigned long long> n2pq(unsigned long long n) {
    if (n == 1)
        return {1, 1};
    else {
        pair<unsigned long long, unsigned long long> ans = n2pq(n >> 1);
        if (n % 2 == 0)
            return {ans.first, ans.first + ans.second};
        else
            return {ans.first + ans.second, ans.second};
    }
}

unsigned long long pq2n(unsigned long long p, unsigned long long q) {
    if (p == 1 && q == 1)
        return 1;
    else if (p > q)
        return (pq2n(p - q, q) << 1) + 1;
    else
        return (pq2n(p, q - p) << 1);
}

int main() {
    unsigned long long T;
    cin >> T;

    for (unsigned long long t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        unsigned long long p, q, n;

        unsigned long long c;
        cin >> c;
        if (c == 1) {
            cin >> n;
            pair<unsigned long long, unsigned long long> ans = n2pq(n);
            cout << ans.first << " " << ans.second << endl;
        } else if (c == 2) {
            cin >> p >> q;
            cout << pq2n(p, q) << endl;
        }
    }

    return 0;
}
