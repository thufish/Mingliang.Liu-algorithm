#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int count;
        cin >> count;
        if (count == 0)
            break;

        string tmp;
        getline(cin, tmp);

        vector<string> finds(10);
        vector<string> replaces(10);
        for (int i = 0; i < count; ++i) {
            getline(cin, finds[i]);
            getline(cin, replaces[i]);
        }

        string str;
        getline(cin, str);

        for (int i = 0; i < count; ++i) {
            bool changed = true;
            while (changed) {
                changed = false;
                size_t pos = 0;
                while ((pos = str.find(finds[i], 0)) != string::npos) {
                    str.replace(pos, finds[i].length(), replaces[i]);
                    changed = true;
                }
            }
        }

        cout << str << endl;
    }

    return 0;
}
