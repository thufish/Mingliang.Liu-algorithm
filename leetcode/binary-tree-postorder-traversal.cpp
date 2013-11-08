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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (!root)
            return ret;
        stack<TreeNode*> S;
        S.push(root);
        TreeNode *last = nullptr;
        while (!S.empty()) {
            TreeNode *curr = S.top();
            if (!last || last->left == curr || last->right == curr) {
                if (curr->left)
                    S.push(curr->left);
                else if (curr->right)
                    S.push(curr->right);
            } else if (curr->left == last) {
                if (curr->right)
                    S.push(curr->right);
            } else {
                ret.push_back(curr->val);
                S.pop();
            }
            last = curr;
        }
        
        return ret;
    }
};
