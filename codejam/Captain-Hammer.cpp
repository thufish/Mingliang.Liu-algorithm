#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        unsigned V, D;
        cin >> V >> D;
        double S = D * 9.8 / V / V;
        double ans = asin(S) * 180.0 / M_PI / 2;

        cout << "Case #" << t << ": ";
        cout << std::fixed << std::setprecision(7) << ans;
        cout << endl;
    }
    return 0;
}
