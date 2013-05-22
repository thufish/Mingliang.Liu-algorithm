#include <iostream>

using namespace std;

int main() {
    long long A, limit;
    long c = 1;
    while (cin >> A >> limit) {
        if (A < 0 && limit < 0)
            break;

        cout << "Case " << (c++) << ": A = " << A << ", limit = " << limit << ", number of terms = ";

        long terms = 1;
        while (true) {
            if (A == 1)
                break;
            else if (A % 2) {
                A = A * 3 + 1; 
                if (A > limit)
                    break;
            } else
                A /= 2;
            terms++;
        }

        cout << terms << endl;
    }
    return 0;
}
