#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
    int min = INT_MAX, max = INT_MIN;

    for (int i = 0; i < (n >> 1); i++) {
        int p, q;
        cin >> p >> q;
        sum += p + q;
        if (p > q) {
            if (q < min)
                min = q;
            if (p > max)
                max = p;
        } else {
            if (p < min)
                min = p;
            if (q > max)
                max = q;
        }
    }

    if (n % 2) {
        int p;
        cin >> p;
        sum += p;
        if (p < min)
            min = p;
        if (p > max)
            max = p;
    }

    cout << max << endl << min << endl << sum << endl;
    return 0;
}
