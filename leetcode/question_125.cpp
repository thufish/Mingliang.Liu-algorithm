#include <ctype>
#include <string>

using namespace std;

/** 
 * NOTE: every time i++ in the while, make the range check for i
 * See line 15-21
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            while (i < j && !isalpha(s[i]) && !isdigit(s[i]))
                ++i;
            while (i < j && !isalpha(s[j]) && !isdigit(s[j]))
                --j;
            if (i >= j)
                break;

            if (tolower(s[i++]) != tolower(s[j--]))
                return false;
        }
            
        return true;
    }
};
