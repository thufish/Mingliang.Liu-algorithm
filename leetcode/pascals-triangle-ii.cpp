class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0)
            return vector<int>();

        vector<int> ans(rowIndex + 1, 0);
        for (int row = 0; row <= rowIndex; row++) {
            ans[row] = 1;
            for (int j = row - 1; j > 0; j--)
                ans[j] += ans[j - 1]; 
        }

        return ans;
    }
};
