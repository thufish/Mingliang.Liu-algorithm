#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string tmp;
    getline(cin, tmp);

    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);

        stack<char> s;
        bool ok = true;

        for (short j = 0; j < str.length(); ++j)
            if (str[j] == '(' || str[j] == '[') {
                s.push(str[j]);
            } else if (str[j] == ')') {
                if (!s.empty() && s.top() == '(')
                    s.pop();
                else {
                    ok = false;
                    break;
                }
            } else if (str[j] == ']') {
                if (!s.empty() && s.top() == '[')
                    s.pop();
                else {
                    ok = false;
                    break;
                }
            } else {
                ok = false;
                break;
            }

        if (ok && s.empty())
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }

    return 0;
}
