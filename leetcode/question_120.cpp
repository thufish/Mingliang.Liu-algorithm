#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

/** O(N) time and O(row) space overhead */
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0)
            return 0;

        vector<int> shortest(triangle.size(), 0);
        shortest[0] = triangle[0][0]; // NOTE: don't push_back!

        for (int row = 1; row < triangle.size(); ++row) {
            int p = shortest[0];
            shortest[0] += triangle[row][0];
            for (int col = 1; col < triangle[row].size() - 1; ++col) {
                int q = triangle[row][col] + min(shortest[col], p);
                p = shortest[col];
                shortest[col] = q;
            }
            shortest[triangle[row].size() - 1] = p + triangle[row][triangle[row].size() - 1];
        }
        
        int ret = INT_MAX;
        for (int i = 0; i < shortest.size(); ++i)
            if (shortest[i] < ret)
                ret = shortest[i];
        return ret;
    }
};
