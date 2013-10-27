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
    int sumNumbers(TreeNode *root) {
        return sumNumbersHelper(root, 0);
    }
    
    int sumNumbersHelper(TreeNode *root, int curr_sum) {
        if (!root)
            return 0;
        
        if (!root->left && !root->right)
             return curr_sum * 10 + root->val;
        else
            return sumNumbersHelper(root->left, curr_sum * 10 + root->val) + 
                   sumNumbersHelper(root->right, curr_sum * 10 + root->val);
    }
};
