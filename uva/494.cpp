#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        int wc = 0;
        int i = 0;
        while (i < str.size()) {
            // skip non-alpha chars
            while (i < str.size() && !isalpha(str[i]))
                i++;
            if (i == str.size())
                break;
            // to the end of the word
            while (i < str.size() && isalpha(str[i]))
                i++;
            wc++;
        }
        cout << wc << endl;
    }
    return 0;
}
