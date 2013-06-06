#include <ctype>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        
        const char *p = s;
        while (*p) {
            // find the start of the word, skip the leading spaces
            while (*p == ' ')
                ++p;
            // if there is no last word
            if (!*p)
                break;
            
            // bypass the new word
            len = 0;
            while (isalpha(*p)) {
                ++p;
                ++len;
            }
        }
        
        return len;
    }
};
