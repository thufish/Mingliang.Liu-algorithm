class Solution {
public:
    string longestPalindrome(string s) {
        ssize_t from = 0, to = 0;
        for (ssize_t i = 0; i < s.length(); i++) {
            ssize_t m = i, n = i;
            while (m >= 0 && s[m] == s[i])
                m--;
            while (n < s.length() && s[n] == s[i])
                n++;
            while (m >= 0 && n < s.length() && s[m] == s[n]) {
                m--;
                n++;
            }
            m++;
            n--;
            if (n - m > to - from) {
                from = m;
                to = n;
            }
        }
        return s.substr(from, to - from + 1);
    }
};
