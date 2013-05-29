#include <string>
#include <iostream>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    while (getline(cin, str)) {
        if (str == "___________")
            break;

        if (str[0] != '|')
            continue;

        int ascii = 0;
        int pow[] = {0, 0, 64, 32, 16, 8, 0, 4, 2, 1};
        for (int i = 2; i < 10; ++i) {
            if (i == 6)
                continue;
            if (str[i] == 'o')
                ascii += pow[i];
        }
        cout << ((char)ascii);
    }

    return 0;
}
