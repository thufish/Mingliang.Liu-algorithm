#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;

        vector<int> ans;
        if (rowIndex <= 0)
            return ans;
        
        ans.push_back(1);
        if (rowIndex == 1)
            return ans;
        ans.push_back(1);
        if (rowIndex == 2)
            return ans;
        
        for (int i = 2; i < rowIndex; i++) {
            vector<int> pre(ans);
            ans.clear();
            ans.push_back(1);
            for (int j = 0; j < pre.size() - 1; j++)
                ans.push_back(pre[j] + pre[j + 1]);
            ans.push_back(1);
        }
        
        return ans;
    }
};
