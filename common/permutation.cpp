#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permutation(vector<int> E, int k) {
    if (k == E.size()) {
        for (int e : E)
            cout << e << " ";
        cout << endl;
        return;
    } else for (int i = k; i < E.size(); i++) {
        swap(E[i], E[k]);
        permutation(E, k + 1);
    }
}

int main() {
    vector<int> E = {1, 2, 5, 10};
    permutation(E, 0);
    return 0;
}
