#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int count;
    cin >> count;
    string tmp;
    getline(cin, tmp);

    while (count-- > 0) {
        string l1;
        getline(cin, l1);
        // split l1
        size_t pos1 = l1.find_first_of("<", 0);
        size_t pos2 = l1.find_first_of(">", pos1);
        size_t pos3 = l1.find_first_of("<", pos2);
        size_t pos4 = l1.find_first_of(">", pos3);

        string s1 = l1.substr(0, pos1);
        string s2 = l1.substr(pos1 + 1, pos2 - pos1 - 1);
        string s3 = l1.substr(pos2 + 1, pos3 - pos2 - 1);
        string s4 = l1.substr(pos3 + 1, pos4 - pos3 - 1);
        string s5 = l1.substr(pos4 + 1);
        cout << s1 << s2 << s3 << s4 << s5 << endl;

        string l2;
        getline(cin, l2);
        cout << l2.substr(0, l2.length() - 3) << s4 << s3 << s2 << s5 << endl;
    }
    return 0;
}
