#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    char sentences[100][100];
    short rows = 0;
    short max_len = 0;

    memset(sentences, 0, 10000);

    string str;
    while (getline(cin, str)) {
        for (short i = 0; i < str.size(); i++)
            sentences[i][rows] = str[i];
        rows++;
        if (str.size() > max_len)
            max_len = str.size();
    }

    for (short i = 0; i < max_len; i++) {
        for (short j = rows - 1; j >= 0; j--) {
            if (sentences[i][j] == '\0')
                cout << ' ';
            else
                cout << sentences[i][j];

        }
        cout << endl;
    }

    return 0;
}
