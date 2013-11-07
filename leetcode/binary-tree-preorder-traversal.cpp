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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        stack<TreeNode*> S;
        TreeNode *curr = root;
        while (!S.empty() || curr) {
            while (curr) {
                ret.push_back(curr->val);
                S.push(curr);
                curr = curr->left;
            }
            while (!curr && !S.empty()) {
                curr = S.top();
                S.pop();
                curr = curr->right;
            }
        }
        
        return ret;
    }
};
