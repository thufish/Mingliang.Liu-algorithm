#include <vector>

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0)
            return NULL;

        return sortedArrayToBST(num, 0, num.size() - 1);
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num, int start, int end) {
        if (start > end)
            return NULL;
        else if (start == end)
            return new TreeNode(num[start]);

        TreeNode *root = new TreeNode(num[(start + end) / 2]);
        root->left = sortedArrayToBST(num, start, (start + end) / 2 - 1);
        root->right = sortedArrayToBST(num, (start + end) / 2 + 1, end);
        
        return root;
    }
};
