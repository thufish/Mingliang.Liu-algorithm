#include <iostream>

using namespace std;

/** v = v0 + at
 *  s = v0t + (at^2)/2
 *
 *  displacement = v0 * 2t + (a * 4t^2) / 2 = 2t(v0 + at) = 2tv
 */
int main() {
    // v in [-100, 100]
    // t in [0, 200]
    // char can not be multiplied with short
    short v, t;

    while (cin >> v >> t)
        cout << 2 * v * t << endl;

    return 0;
}
