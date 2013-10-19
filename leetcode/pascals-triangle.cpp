class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> a;
            a.push_back(1);
            for (int j = 1; j < i; j++)
                a.push_back(ans.back()[j - 1] + ans.back()[j]);
            if (i > 0)
                a.push_back(1);
            ans.push_back(a);
        }
        return ans;
    }
};
