/** The naive solution with backtracing, which can not pass the large size */
class Solution {
public:
    int minCut(string s) {
        vector<string> ans = {""};
        int m = s.length() - 1;
        return minCutHelper(s, 0, ans, m);
    }
    
    int minCutHelper(const string &s, int index, vector<string> ans, int &m) {
        if (ans.size() >= m)
            return m;

        if (index == s.length()) {
            if (isPalindrome(ans.back())) {
                m = min(m, (int)ans.size() - 1);
                return ans.size() - 1;
            }
            return s.length();
        } else {
            ans.back().push_back(s[index]);
            int cut1 = minCutHelper(s, index + 1, ans, m);
            m = min(cut1, m);
            ans.back().pop_back();
            
            int cut2 = s.length();
            if (isPalindrome(ans.back())) {
                ans.push_back(s.substr(index, 1));
                cut2 = minCutHelper(s, index + 1, ans, m);
            }
            
            m = min(cut1, cut2);
            return min(cut1, cut2);
        }
    }
    
    inline bool isPalindrome(const string &s) {
        if (s.empty())
            return false;
            
        for (int i = 0; i < s.length() / 2; i++)
            if (s[i] != s[s.length() - 1 - i])
                return false;
        
        return true;
    }
};

class Solution {
public:
    int minCut(string str) {

        int leng = str.size();
        
        int dp[leng+1];
        for(int i = 0; i <= leng; i++)
            dp[i] = leng-i;
        
        vector<vector<bool>> palin(leng, vector<bool>(leng, false));
        for(int i = leng-1; i >= 0; i--)
            for(int j = i; j < leng; j++)
                if(str[i] == str[j] && (j - i < 2 || palin[i+1][j-1])) {
                    palin[i][j] = true;
                    dp[i] = min(dp[i], dp[j + 1] + 1);
                }

        return dp[0]-1;
    }
};
