#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> multiply(const vector<int> &l, const vector<int> &r);

int main() {
    string str;
    while (getline(cin, str)) {
        if (str.empty())
            continue;

        // pre-process the string
        int start = 0;
        int end = 5;
        // skip the leading 0
        while (start < end && str[start] == '0')
            ++start;
        int dot = str.find(".");
        // skip the post 0
        while (dot >= 0 && str[end] == '0')
            --end;
        dot = dot >= 0 ? end - dot : 0;
        vector<int> R;
        while (end >= start) {
            if (str[end] != '.')
                R.push_back(str[end] - '0');
            --end;
        }

        int n = str[8] - '0';
        n += str[7] == ' ' ? 0 : (str[7] - '0') * 10; // NOTE: str[7] == ' ' ?
        dot *= n; // NOTE: n is going to be modified. calc dot here!

        if (n == 0) {
            cout << "1" << endl;
            continue;
        } else if (R.size() == 0 || (R.size() == 1 && R[0] == 0)) {
            cout << "0" << endl;
            continue;
        }

        vector<int> ans;
        ans.push_back(1);
        while (n > 0) {
            if (n % 2)
                ans = multiply(ans, R); 
            R = multiply(R, R);
            n /= 2;
        }

        end = ans.size() - 1;
        while (ans[end] == 0)
            --end;
        start = 0;
        while (dot > 0 && ans[start] == 0)
            ++start;
        if (dot - 1 > end)
            cout << ".";
        for (int i = dot - 1; i > end; --i)
            cout << "0";
        for (; end >= start; --end) {
            if (end == dot - 1)
                cout << ".";
            cout << ans[end];
        }
        cout << endl;
    }

    return 0;
}

vector<int> multiply(const vector<int> &l, const vector<int> &r) {
    vector<int> ans(l.size() + r.size() - 1, 0);
    for (int i = 0; i < l.size(); ++i)
        for (int j = 0; j < r.size(); ++j) {
            ans[i + j] += l[i] * r[j];
        }

    int carry = 0;
    for (int i = 0; i < ans.size(); ++i) {
        int new_carry = (ans[i] + carry) / 10;
        ans[i] = (ans[i] + carry) % 10;
        carry = new_carry;
    }
    if (carry > 0)
        ans.push_back(carry);

    return ans;
}
