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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if (!root)
            return ret;
            
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty()) {
            queue<TreeNode *> NQ;
            vector<int> L;
            while (!Q.empty()) {
                TreeNode *n = Q.front();
                Q.pop();
                L.push_back(n->val);
                if (n->left)
                    NQ.push(n->left);
                if (n->right)
                    NQ.push(n->right);
            }
            ret.push_back(L);
            Q = NQ;
        }
        
        return ret;
    }
};
