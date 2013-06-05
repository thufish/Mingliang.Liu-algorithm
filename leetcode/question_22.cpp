#include <vector>
#include <string>

using namespace std;

/** The recusive version */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        generateParenthesisHelper(ans, str, n, n);
        return ans;
    }
    
    /** The recursive helper
     *
     * @param ans the answer of the question
     * @param str the string of the current ()s
     * @param left the remaining '('
     * @param right the remaining ')'
     */
    void generateParenthesisHelper(vector<string> &ans, string str, int left, int right) {
        if (left > right)
            return;
        
        if (left == 0) {
            for (int i = 0; i < right; ++i)
                str.push_back(')');
            ans.push_back(str);
        } else {
            if (left < right) {
                str.push_back(')');
                generateParenthesisHelper(ans, str, left, right - 1);
                str.pop_back();
            }
            str.push_back('(');
            generateParenthesisHelper(ans, str, left - 1, right);
        }
    }
};

int main() {
    Solution S;
    auto ans = S.generateParenthesis(2);
    return 0;
}
