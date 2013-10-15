class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        const char *p = s + len - 1;
        while (len > 0 && *p == ' ') {
            p--;
            len--;
        }
        const char *q = p;
        while (len > 0 && *q != ' ') {
            q--;
            len--;
        }
        return p - q;
    }
};
