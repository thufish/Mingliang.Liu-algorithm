class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return string();
    
        int len = 0;
        while (true) {
            int ok = true;
            char c = strs[0][len];
            for (string s : strs)
                if (len >= s.length() || s[len] != c) {
                    ok = false;
                    break;
                }
            if (!ok)
                break;
            len++;
        }
        return strs[0].substr(0, len);
    }
};
