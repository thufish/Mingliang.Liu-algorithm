class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> numbers = {"", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s;
        letterCombinationsHelper(digits, 0, numbers, s, ans);
        return ans;
    }
    
    void letterCombinationsHelper(const string &digits, int index, const vector<string> &numbers, string s, vector<string> &ans) {
        if (index == digits.length()) {
            ans.push_back(s);
            return;
        }
        
        for (int i = 0; i < numbers[digits[index] - '0'].length(); i++) {
            s.push_back(numbers[digits[index] - '0'][i]);
            letterCombinationsHelper(digits, index + 1, numbers, s, ans);
            s.pop_back();
        }
    }
};
