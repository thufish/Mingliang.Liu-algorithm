#include <cstring>

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (!haystack)
            return NULL;
        else if (!needle)
            return haystack + strlen(haystack);
        
        int hlen = strlen(haystack);
        int nlen = strlen(needle);
        for (int i = 0; i < hlen - nlen + 1; i++) {
            bool ok = true;
            for (int j = 0; ok && j < nlen; j++)
                if (needle[j] != haystack[i + j])
                    ok = false;
            if (ok)
                return haystack + i;
        }
        
        return NULL;
    }
};
