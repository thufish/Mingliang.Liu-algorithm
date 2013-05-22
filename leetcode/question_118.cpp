#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> triangle;
        
        if (numRows == 0)
            return triangle;
                
        vector<int> vp = {1};
        triangle.push_back(vp);
        if (numRows == 1)
            return triangle;
        
        vp.push_back(1);
        triangle.push_back(vp);
        if (numRows == 2)
            return triangle;
        
        for (int i = 2; i < numRows; i++) {
            vector<int> vc = {1};
            
            // add more elements
            for (int j = 0; j < triangle[i - 1].size() - 1; j++)
                vc.push_back(triangle[i - 1][j] + triangle[i - 1][j + 1]);
            
            vc.push_back(1);
            triangle.push_back(vc);
        }
        
        return triangle;
    }
};
