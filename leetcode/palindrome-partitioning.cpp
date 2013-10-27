class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> a = {""};
        partitionHelper(s, 0, ans, a);
        return ans;
    }
    
    void partitionHelper(string &s, int index, vector<vector<string>> &ans, vector<string> a) {
        if (index == s.length()) {
            // judge the a.back()
            if (isPalindrome(a.back()))
                ans.push_back(a);
        } else {
            a.back().push_back(s[index]);
            partitionHelper(s, index + 1, ans, a);
            a.back().pop_back();
            
            if (isPalindrome(a.back())) {
                a.push_back(s.substr(index, 1));
                partitionHelper(s, index + 1, ans, a);
            }
        }
    }
    
    inline bool isPalindrome(const string &s) {
        if (s.empty())
            return false;

        bool ok = true;
        for (int i = 0; ok && i < s.length() / 2; i++)
            if (s[i] != s[s.length() - 1 - i])
                ok = false;
        return ok;
    }
};
