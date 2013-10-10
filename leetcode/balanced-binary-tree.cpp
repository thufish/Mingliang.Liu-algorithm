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
    bool isBalanced(TreeNode *root) {
        return isBalancedHeight(root) != -1;
    }
    
    int isBalancedHeight(TreeNode *root) {
        if (root == NULL)
            return 0;
        
        int left_height = isBalancedHeight(root->left);
        if (left_height == -1)
            return -1;
        
        int right_height = isBalancedHeight(root->right);
        if (right_height == -1)
            return -1;
        
        int diff = left_height - right_height;
        if (abs(diff) > 1)
            return -1;
        else
            return max(left_height, right_height) + 1;
    }
};
