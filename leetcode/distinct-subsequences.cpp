/** The very naive dfs solution */
class Solution {
public:
    int numDistinct(string S, string T) {
        return numDistinctHelper(S, T, 0, 0);
    }
    
    int numDistinctHelper(const string &S, const string &T, int indexs, int indext) {
        if (indext == T.length()) {
            return 1;
        } else {
            int sum = 0;
            for (int i = indexs; i < S.length(); i++)
                if (S[i] == T[indext])
                    sum += numDistinctHelper(S, T, i + 1, indext + 1);
            return sum;
        }
    }
};

/** The DP solution. O(m*n) time and O(n) space */
class Solution {
public:
    int numDistinct(string S, string T) {
        vector<int> dp(T.length(), 0);
        dp.push_back(1);
        
        /** Let dp(i, j) the number of distinct subsequences of T(j:) in S(i:)
         *      dp(i, j) = dp(i + 1, j) + (S[i] == T[j]) * dp(i + 1, j + 1)
         */
        for (int i = S.length() - 1; i >= 0; i--)
            for (int j = 0; j < T.length(); j++)
                dp[j] += (S[i] == T[j]) * dp[j + 1];
        
        return dp.front();
    }
};
