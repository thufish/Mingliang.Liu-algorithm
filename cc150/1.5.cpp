#include <string>
#include <sstream>
#include <iostream>

using namespace std;

string compressString(const string &str) {
    stringstream ss;

    int len = 0;
    char p = 0;
    int count = 1;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == p)
            ++count;
        else {
            if (p)
                ss << p << count;

            ++len;
            while (count > 0) {
                ++len;
                count /= 10;
            }
            if (len > str.length())
                return str;

            p = str[i];
            count = 1;
        }
    }

    // for the last character
    ss << p << count;
    ++len;
    while (count > 0) {
        ++len;
        count /= 10;
    }
    if (len > str.length())
        return str;

    return ss.str();
}

int main() {
    string str1 = "aabcccccaaa";
    string str2 = "abcdef";
    string str3 = "aab";
    cout << compressString(str1) << endl;
    cout << compressString(str2) << endl;
    cout << compressString(str3) << endl;
    return 0;
}
