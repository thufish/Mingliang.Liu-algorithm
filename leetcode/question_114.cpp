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
    bool hasPathSum(TreeNode *root, int sum) {
        // NULL pointer
        if (root == NULL)
            return false;
            
        // for leaf node
        if (root->left == NULL && root->right == NULL)
            if (root->val == sum)
                return true;
            else
                return false;
        
        // mature optimization
        // if (sum < val)
        //    return false;
        
        // for internal node
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};
