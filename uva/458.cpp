#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        for (int i = 0; i < str.length(); i++)
            cout << (char)(str[i] - 7);
        cout << endl;
    }
    return 0;
}
