#include <iostream>
#include <string>

using namespace std;

void reverse1(string &str) {
    // this is important since j is unsigned size_t
    if (str.size() < 1)
        return;

    size_t i = 0;
    size_t j = str.length() - 1;

    while (i < j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        ++i;
        --j;
    }
}

void reverse2(char *str) {
    if (str == nullptr)
        return;

    char *end = str;
    while (*end) {
        ++end;
    }
    --end;
    while (str < end) {
        char c = *str;
        *str++ = *end;
        *end-- = c;
    }
}

int main() {
    string a = "abcdefghijklml";
    string b = "abccba";
    string c = "d";
    string d = "";
    reverse1(a);
    reverse1(b);
    reverse1(c);
    reverse1(d);
    cout << a << " " << b << " " << c << " " << d << endl;

    char aa[] = "abcdefghijklml\0";
    char bb[] = "abccba\0";
    char cc[] = "d\0";
    char dd[] = "\0";
    reverse2(aa);
    reverse2(bb);
    reverse2(cc);
    reverse2(dd);
    cout << aa << " " << bb << " " << cc << " " << dd << endl;

    return 0;
}
