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
        if (root == NULL)
            return 0;

        int max_sum = INT_MIN, current_sum = 0;
        maxPathSumHelper(root, current_sum, max_sum);
        return max_sum;
    }
    
    void maxPathSumHelper(TreeNode *root, int &current_sum, int &max_sum) {
        if (root == NULL)
            return;
        
        int lsum = 0;
        maxPathSumHelper(root->left, lsum, max_sum);
        int rsum = 0;
        maxPathSumHelper(root->right, rsum, max_sum);
        
        current_sum = root->val + max(0, max(lsum, rsum));
        max_sum = max(max_sum, max(current_sum, lsum + root->val + rsum));
    }
};
