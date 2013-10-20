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
    int maxPathSum(TreeNode *root) {
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }
    
    int maxPathSum(TreeNode *root, int &ans) {
        if (!root)
            return 0;
        int l = maxPathSum(root->left, ans);
        int r = maxPathSum(root->right, ans);
        ans = max(ans, l + root->val);
        ans = max(ans, root->val + r);
        ans = max(ans, l + root->val + r);
        ans = max(ans, root->val);
        return max(max(l + root->val, root->val), root->val + r);
    }
};
