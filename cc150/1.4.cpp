#include <iostream>

using namespace std;

void replaceSpaces(char *str, int len) {
    // find the count of spaces
    int count = 0;
    for (int i = 0; i < len; ++i)
        if (str[i] == ' ')
            ++count;

    // copy from backwards
    int end = len + 2 * count;
    str[end] = '\0';
    for (int i = len - 1; i >= 0; --i) {
        if (str[i] != ' ')
            str[--end] = str[i];
        else {
            str[--end] = '0';
            str[--end] = '2';
            str[--end] = '%';
        }
    }
}

int main() {
    char s[128] = "a b cc d    ee \0";
    replaceSpaces(s, strlen(s));
    cout << s << endl;
    return 0;
}
