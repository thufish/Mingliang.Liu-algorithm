#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool starts_with(string &s1, string &s2) {
    int i = 0;
    int j = 0;
    while (i < s1.size() && j < s2.size() && s1[i] == s2[j]) {
        i++;
        j++;
    }

    if (i == s1.size() || j == s2.size())
        return true;
    else
        return false;
}

int main() {
    int cases = 0;
    string str;
    vector<string> vec;
    while (cin >> str) {
        if (!str.empty() && str[0] == '9') {
            bool ok = true;
            for (int i = 0; ok && i < vec.size(); ++i)
                for (int j = i + 1; ok && j < vec.size(); ++j)
                    if (starts_with(vec[i], vec[j]))
                        ok = false;

            cout << "Set " << ++cases << " is ";
            if (!ok)
                cout << "not ";
            cout << "immediately decodable" << endl;
            vec.clear();
        } else
            vec.push_back(str);
    }

    return 0;
}
