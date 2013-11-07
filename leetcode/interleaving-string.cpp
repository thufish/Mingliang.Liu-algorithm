/** DFS solution. Can NOT pass the large data set */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        return isInterleaveHelper(s1, 0, s2, 0, s3, 0);
    }
    
private:
    bool isInterleaveHelper(string &s1, int index1, string &s2, int index2, string &s3, int index3) {
        if (index1 == s1.length())
            return s2.substr(index2) == s3.substr(index3);
        else if (index2 == s2.length())
            return s1.substr(index1) == s3.substr(index3);
        else if (index3 == s3.length())
            return false;
        else if (s1[index1] != s2[index2]) {
            if (s3[index3] == s1[index1])
                return isInterleaveHelper(s1, index1 + 1, s2, index2, s3, index3 + 1);
            else if (s3[index3] == s2[index2])
                return isInterleaveHelper(s1, index1, s2, index2 + 1, s3, index3 + 1);
            else
                return false;
        } else
            return  s3[index3] == s1[index1] &&
                    (isInterleaveHelper(s1, index1 + 1, s2, index2, s3, index3 + 1) ||
                     isInterleaveHelper(s1, index1, s2, index2 + 1, s3, index3 + 1));
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        
        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, true));
        for (int j = 1; j <= s1.length(); j++)
            dp[j][0] = dp[j - 1][0] && s1[j - 1] == s3[j - 1];
        for (int i = 1; i <= s2.length(); i++)
            dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];

        for (int i = 1; i <= s1.length(); i++)
            for (int j = 1; j <= s2.length(); j++) {
                dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) ||
                           (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
            }
                
        return dp.back().back();
    }
};
