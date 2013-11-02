#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.length();

    for (int L = len / 2; L > 0; L--) {
        vector<long> s(len, 0), f(len, 0), g(len, 0);
        for (int i = 0; i < L; i++) {
            s[0] += str[i] - '0'; 
            f[0] += (2 * i + 1) * (str[i] - '0');
            g[0] += (2 * (L - i) - 1) * (str[i] - '0');
        }
        for (int i = 1; i < len - L + 1; i++) {
            s[i] = s[i - 1] - (str[i - 1] - '0') + (str[i + L - 1] - '0');
            f[i] = f[i - 1] - 2 * s[i - 1] + (str[i - 1] - '0') + (2 * L - 1) * (str[i + L - 1] - '0');
            g[i] = g[i - 1] + 2 * s[i - 1] - (2 * L + 1) * (str[i - 1] - '0') + (str[i + L - 1] - '0');
        }

        unordered_map<long, int> dict;
        for (int i = 0; i < len - 2 * L + 1; i++) {
            dict.insert({f[i], i});
            dict.insert({g[i], i});
            if (dict.find(f[i + L]) != dict.end()) {
                cout << dict[f[i + L]] << " " << i + L << " " << L;
                return 0;
            }
            if (dict.find(g[i + L]) != dict.end()) {
                cout << dict[g[i + L]] << " " << i + L << " " << L;
                return 0;
            }
        }
    }

    return 0;
}
