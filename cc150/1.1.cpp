#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/** Use a bool vector for duplication detection
 * Time:  O(N)
 * Space: O(1)
 */
bool is_all_uniq1(const string &str) {
    if (str.size() > 256)
        return false;

    vector<bool> taken(128, false);
    for (char c : str) {
        if (taken[c])
            return false;
        taken[c] = true;
    }
    return true;
}

/************ No additional data structure is needed ***********/

/** Sort the str first and uniq
 * Time:  O(NlgN)
 * Space: O(lgN) for quick sort in STL
 */
bool is_all_uniq2(string &str) {
    if (str.size() > 256)
        return false;

    sort(str.begin(), str.end());
    return unique(str.begin(), str.end()) == str.end();
}

/** Use the manual bit vector
 * Time:  O(N)
 * Space: O(1)
 */
bool is_all_uniq3(const string &str) {
    if (str.size() > 256)
        return false;

    int taken0, taken1, taken2, taken3;
    for (char c: str) {
        int *taken;
        if (c < 32)
            taken = &taken0;
        else if (c < 64)
            taken = &taken1;
        else if (c < 96)
            taken = &taken2;
        else
            taken = &taken3;

        if (*taken & (1 << (c % 32)))
            return false;
        *taken = *taken | (1 << (c % 32));
    }

    return true;
}

int main() {
    string a = "abdkjfakdjkha;kdjkfjdkakdhrjkjdkajf;kdjrkj3;kaka;vna;kjf";
    string b = "abcdefghi8*k";
    string c = ";;";
    cout << is_all_uniq1(a) << is_all_uniq1(b) << is_all_uniq1 (c) << endl;
    cout << is_all_uniq2(a) << is_all_uniq2(b) << is_all_uniq2 (c) << endl;
    cout << is_all_uniq3(a) << is_all_uniq3(b) << is_all_uniq3 (c) << endl;
    return 0;
}
