#include <iostream>

#define ABS(a,b) ((a) > (b) ? ((a) - (b)) : ((b) - (a)))

using namespace std;

int main() {
    // unsigned int a, b;
    long long a, b;

    while (cin >> a >> b) {
        cout << ABS(a, b) << endl;
    }

    return 0;
}
