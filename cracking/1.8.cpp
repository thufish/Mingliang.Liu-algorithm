#include <string>
#include <iostream>

using namespace std;

bool is_rotation(const string &s1, const string &s2) {
    // NOTE: always consider the trivial case
    if (s1.length() != s2.length())
        return false;
    else {
        string s1s1 = s1 + s1;
        return s1s1.find(s2) != string::npos;
    }
}

int main() {
    string s1 = "abc";
    string s2 = "cba";
    string s3 = "cab";
    string s4 = "ab";
    string s5 = "";
    cout << is_rotation(s1, s2) << endl;
    cout << is_rotation(s1, s3) << endl;
    cout << is_rotation(s1, s4) << endl;
    cout << is_rotation(s1, s5) << endl;
    return 0;
}
