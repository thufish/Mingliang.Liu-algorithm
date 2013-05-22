#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int times;
    cin >> times;

    for (int t = 0; t < times; t++) {
        int A, F;
        cout << endl;

        cin >> A >> F;

        for (int i = 0; i < F; i++) {
            // print each wave
            for (int j = 1; j <= A; j++) {
                for (int k = 0; k < j; k++)
                    cout << j;
                cout << endl;
            }
            for (int j = A - 1; j >= 1; j--) {
                for (int k = 0; k < j; k++)
                    cout << j;
                cout << endl;
            }
     
            // print the seperate line
            if (i != F - 1)
                cout << endl;
        }
    }
    return 0;
}
