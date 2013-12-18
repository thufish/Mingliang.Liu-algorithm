class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        
        int ret = 0;
        int start_index;
        bool table[1000][1000] = {false};
        
        for (int i = s.length() - 1; i >= 0; i--)
            for (int j = i; j < s.length(); j++) {
                table[i][j] = (s[i] == s[j]) && (j - i < 2 || table[i + 1][j - 1]);
                if (table[i][j] && j - i + 1 > ret) {
                    ret = j - i + 1;
                    start_index = i;
                }
            }
        
        return s.substr(start_index, ret);
    }
};
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
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        
        int ret = 0;
        int start_index;
        bool table[1000][1000] = {false};
        
        for (int i = s.length() - 1; i >= 0; i--)
            for (int j = i; j < s.length(); j++) {
                table[i][j] = (s[i] == s[j]) && (j - i < 2 || table[i + 1][j - 1]);
                if (table[i][j] && j - i + 1 > ret) {
                    ret = j - i + 1;
                    start_index = i;
                }
            }
        
        return s.substr(start_index, ret);
    }
};
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
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        
        int ret = 0;
        int start_index;
        bool table[1000][1000] = {false};
        
        for (int i = s.length() - 1; i >= 0; i--)
            for (int j = i; j < s.length(); j++) {
                table[i][j] = (s[i] == s[j]) && (j - i < 2 || table[i + 1][j - 1]);
                if (table[i][j] && j - i + 1 > ret) {
                    ret = j - i + 1;
                    start_index = i;
                }
            }
        
        return s.substr(start_index, ret);
    }
};
