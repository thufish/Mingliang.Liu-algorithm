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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ret;
        queue<TreeNode*> Q;
        if (root)
            Q.push(root);
        while (!Q.empty()) {
            vector<int> L;
            queue<TreeNode*> P;
            while (!Q.empty()) {
                TreeNode *n = Q.front();
                Q.pop();
                L.push_back(n->val);
                if (n->left)
                    P.push(n->left);
                if (n->right)
                    P.push(n->right);
            }
            Q = P;
            ret.push_back(L);
        }
        
        return vector<vector<int>>(ret.rbegin(), ret.rend());
    }
};
