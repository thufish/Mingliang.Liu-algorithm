class Solution {
public:
    string convert(string s, int nRows) {
        vector<string> matrix(nRows);
        bool down = false;
        for (size_t i = 0; i < s.length();) {
            for (int j = 0; i < s.length() && j < nRows; j++)
                matrix[j].push_back(s[i++]);
            for (int j = nRows - 2; i < s.length() && j > 0; j--)
                matrix[j].push_back(s[i++]);
        }
        
        string ans;
        for (int j = 0; j < nRows; j++)
            for (int k = 0; k < matrix[j].length(); k++)
                ans.push_back(matrix[j][k]);

        return ans;
    }
};
