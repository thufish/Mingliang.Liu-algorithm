#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    string tmp;
    getline(cin, tmp);
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        getline(cin, tmp);
        string max_str;
        int cost = 0;
        for (int n = 0; n < N; n++) {
            string str;
            getline(cin, str);
            if (str < max_str)
                ++cost;
            else if (str > max_str)
                max_str = str;
        }
        cout << "Case #" << t << ": " << cost << endl;
    }

    return 0;
}
