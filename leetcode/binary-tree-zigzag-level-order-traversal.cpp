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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;

        bool left2right = true;
        
        queue<TreeNode *> Q;
        Q.push(root);
        Q.push(nullptr);
        vector<int> level;
        while (!Q.empty()) {
            TreeNode *p = Q.front();
            Q.pop();
            if (p) {
                level.push_back(p->val);
                if (p->left)
                    Q.push(p->left);
                if (p->right)
                    Q.push(p->right);
            } else {
                if (!left2right)
                    reverse(level.begin(), level.end());
                ret.push_back(level);
                level.clear();
                
                left2right = !left2right;
                if (!Q.empty())
                    Q.push(nullptr);
            }
        }
        
        return ret;
    }
};
