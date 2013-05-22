#include <string>
#include <iostream>

using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        if (str.size() == 0) {
            cout << endl;
            continue;
        }

        int sum = 0;
        for (int i = 0; i < str.size(); i++)
            if (isdigit(str[i]))
                sum += str[i] - '0';
            else if (str[i] == '!')
                cout << endl;
            else {
                for (int j = 0; j < sum; j++)
                    cout << (str[i] == 'b' ? ' ' : str[i]);
                sum = 0;
            }
        cout << endl;
    }
    return 0;
}
