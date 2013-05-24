#include <iterator>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dump(const vector<int> &dishes) {
    for (int i = 0; i < 40; i++)
        switch (dishes[i]) {
            case 0:
                cout << " ";
                break;
            case 1:
                cout << ".";
                break;
            case 2:
                cout << "x";
                break;
            case 3:
                cout << "W";
                break;
        }
    cout << endl;
}

void transform(vector<int> &dishes, const vector<int> &dna) {
    int p, q;
    p = q = 0;
    for (int i = 0; i < 40; i++) {
        p = q;
        q = dishes[i];
        dishes[i] = dna[p + q + dishes[i + 1]];
    }
}

int main() {
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++) {
        vector<int> dna(11, 0);
        for (int i = 0; i < 10; i++)
            cin >> dna[i];
        vector<int> dishes(40, 0);
        dishes[19] = 1;
        dump(dishes);

        for (int i = 1; i < 50; i++) {
            transform(dishes, dna);
            dump(dishes);
        }

        if (c != cases - 1)
            cout << endl;
    }

    return 0;
}
