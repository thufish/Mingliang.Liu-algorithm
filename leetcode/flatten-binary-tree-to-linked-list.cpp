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
    void flatten(TreeNode *root) {
        flattenHelper(root);
    }
    
    TreeNode *flattenHelper(TreeNode *root) {
        if (root == NULL)
            return NULL;
        
        TreeNode *left_tail = flattenHelper(root->left);
        TreeNode *right_tail = flattenHelper(root->right);
        if (root->left) {
            left_tail->right = root->right;
            root->right = root->left;
        }
        root->left = NULL;
        if (right_tail)
            return right_tail;
        else if (left_tail)
            return left_tail;
        else
            return root;
    }
};
