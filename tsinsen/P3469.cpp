#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
    int ret = 0;
    int N;
    cin >> N;
    
    vector<int> numbers(N + 1, 0);
    numbers[0] = INT_MIN;
    bool pre_larger = false;
    for (int i = 1; i < N + 1; i++) {
        cin >> numbers[i];
        if (pre_larger && numbers[i] < numbers[i - 1])
            ret++;
        pre_larger = numbers[i] > numbers[i - 1];
    }
    ret += pre_larger;

    cout << ret << endl;

    return 0;
}
