#include <iostream>

using namespace std;

int main() {
    short total_cases;
    cin >> total_cases;

    for (short i = 0; i < total_cases; i++) {
        short farmers;
        cin >> farmers;
        int total = 0;
        for (short j = 0; j < farmers; j++) {
            unsigned field, animals, env;
            cin >> field >> animals >> env;
            total += field * env;
        }
        cout << total << endl;
    }

    return 0;
}
