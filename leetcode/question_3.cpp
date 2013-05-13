#include <algorithm>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        else if (s.size() == 1)
            return 1;
        else if (s.size() == 2)
            if (s[0] == s[1])
                return 1;
            else
                return 2;
        
        int max_len = 0;
        
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char> chars;
            int len = 0;
            for (int j = i; j < s.size(); j++)
                if (chars.count(s[j]))
                    break;
                else {
                    chars.insert(s[j]);
                    len++;
                }
            if (len > max_len)
                max_len = len;
        }

        return max_len;
    }
};
