/** The very naive solution of DP using O(mn) space and time */

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

enum {
    UP = 10,
    LEFT = 11,
    UP_LEFT = 12
};

vector<vector<int>> c;
vector<vector<int>> b;

/** 15.4-3 : The memorized version in O(mn) time */
int lcs_len1(const string &s1, const string &s2, int i, int j) {
    if (i == 0 || j == 0)
        return 0;

    if (c[i][j] < 0) {
        if (s1[i - 1] == s2[j - 1])
            c[i][j] = lcs_len1(s1, s2, i - 1, j - 1) + 1;
        else
            c[i][j] = max(lcs_len1(s1, s2, i - 1, j), lcs_len1(s1, s2, i, j - 1));
    }

    return c[i][j];
}

/** The DP version of the program */
void lcs_len2(const string &s1, const string &s2) {
    for (int i = 1; i <= s1.size(); i++)
        for (int j = 1; j <= s2.size(); j++)
            if (s1[i - 1] == s2[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = UP_LEFT;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = UP;
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = LEFT;
            }
}

/** 15.4-4 : Using only 2 * min(m, n) entries in the c table plus O(1) additional space. */
int lcs_len3(const string &s1, const string &s2) {
    if (s1.empty() || s2.empty())
        return 0;
    if (s1.size() < s2.size())
        return lcs_len3(s2, s1);

    int max_len = 0;

    vector<int> prev(s2.size(), 0);
    vector<int> curr(s2.size(), 0);

    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                if (i == 0 || j == 0)
                    curr[j] = 1;
                else
                    curr[j] = prev[j - 1] + 1;
                max_len = max(max_len, curr[j]);
            } else {
                if (i == 0 || j == 0)
                    curr[j] = 0;
                else
                    curr[j] = max(curr[j - 1], prev[j]);
            }
        }
        prev.swap(curr);
    }

    return max_len;
}

/** 15.4-4 : Using only min(m, n) entries plus O(1) additional space. */
int lcs_len4(const string &s1, const string &s2) {
    if (s1.empty() || s2.empty())
        return 0;
    if (s1.size() < s2.size())
        return lcs_len3(s2, s1);

    int max_len = 0;

    vector<int> curr(s2.size(), 0);

    for (int i = 0; i < s1.size(); i++) {
        // TODO: implement me!
        int tmp = 0;
        for (int j = 0; j < s2.size(); j++) {
            tmp = curr[j - 1];
            if (s1[i] == s2[j]) {
                if (i == 0 || j == 0)
                    curr[j] = 1;
                else {
                    curr[j] = tmp + 1;
                }
            } else {
                if (i == 0 || j == 0)
                    curr[j] = 0;
                else
                    curr[j] = max(curr[j - 1], curr[j]);
            }
        }
    }

    return max_len;
}

void lcs_print1(const string &s1, int i, int j) {
    if (i == 0 || j == 0)
        return;
    
    if (b[i][j] == UP_LEFT) {
       lcs_print1(s1, i - 1, j - 1);
       cout << s1[i - 1];
    } else if (b[i][j] == UP)
       lcs_print1(s1, i - 1, j);
    else
       lcs_print1(s1, i, j - 1);
}

/** 15.4-2 : print without using the b table */
void lcs_print2(const string &s1, const string &s2, int i, int j) {
    if (i == 0 || j == 0)
        return;

    if (c[i][j] == c[i - 1][j])
        lcs_print2(s1, s2, i - 1, j);
    else if (c[i][j] == c[i][j - 1])
        lcs_print2(s1, s2, i, j - 1);
    else {
        lcs_print2(s1, s2, i - 1, j - 1);
        cout << s1[i - 1];
    }
}

int main() {
    string s1 = "ABCBDAB";
    string s2 = "BDCABA";

    c = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    b = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    for (int i = 0; i < s1.size() + 1; i++)
        c[i][0] = b[i][0] = 0;
    for (int i = 0; i < s2.size() + 1; i++)
        c[0][i] = b[0][i] = 0;

    assert(lcs_len1(s1, s2, s1.size(), s2.size()) == 4);

    //lcs_len2(s1, s2);
    //lcs_print1(s1, s1.size(), s2.size()); cout << endl;

    lcs_print2(s1, s2, s1.size(), s2.size()); cout << endl;

    assert(lcs_len3(s1, s2) == 4);
    assert(lcs_len4(s1, s2) == 4);

    return 0;
}
