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
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
    
    bool isValidBST(TreeNode *root, int min, int max) {
        if (root == NULL)
            return true;
        else if (root->val < min || root->val > max)
            return false;
        else
            return isValidBST(root->left, min, root->val - 1) &&
                   isValidBST(root->right, root->val + 1, max);
    }
};
