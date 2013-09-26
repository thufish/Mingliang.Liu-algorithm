class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        generateParenthesis(n, 0, str, ans);
        return ans;
    }
    
    void generateParenthesis(const int n, int l, string str, vector<string> &ans) {
        if (str.size() == 2 * n) {
            ans.push_back(str);
        } else if (l == n) {
            for (int i = str.size(); i < 2 * n; i++)
                str.push_back(')');
            ans.push_back(str);
        } else if (l < n) {
            str.push_back('(');
            generateParenthesis(n, l + 1, str, ans); // add one '('
            str.pop_back();

            if (l > str.size() / 2) {
                str.push_back(')');
                generateParenthesis(n, l, str, ans);
            }
        }
    }
};
