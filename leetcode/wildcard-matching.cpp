class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!s && !p)
            return true;
        else if (!s || !p)
            return false;
        
        const char *star_s = nullptr, *star_p = nullptr;
        
        while (*s) {
            if (*s == *p || *p == '?') {
                s++;
                p++;
            } else if (*p == '*') {
                while (*p == '*')
                    p++;
                if (*p == '\0')
                    return true;
                star_s = s;
                star_p = p;
            } else if ((star_p != nullptr) && (*s != *p || *p == '\0')) {
                s = ++star_s;
                p = star_p;
            } else {
                return false;
            }
        }
        
        while (*p == '*')
            p++;
        
        return *p == '\0';
    }
};
