#include <sstream>

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        if (n < 2)
            return str;

        for (int i = 1; i < n; i++)
            str = countAndSay(str);
        return str;
    }
    
    string countAndSay(string str) {
        stringstream ss;
        if (str.empty())
            return ss.str();
        
        char pre = str[0];
        int count = 1;
        for (int i = 1; i < str.length(); i++) {
            if (str[i] == pre)
                count++;
            else {
                ss << count << pre;
                pre = str[i];
                count = 1;
            }
        }
        ss << count << pre;
        
        return ss.str();
    }
};
