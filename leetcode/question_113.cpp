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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > paths;
        
        // NULL pointer
        if (root == NULL)
            return paths;
        
        // leaf node
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                vector<int> p;
                p.push_back(root->val);
                paths.push_back(p);
            }
        } else { // internal node
            vector<vector<int> > left_paths = pathSum(root->left, sum - root->val);
            for (auto v : left_paths) {
                vector<int> p;
                p.push_back(root->val);
                for (auto i = v.begin(); i != v.end(); ++i)
                    p.push_back(*i);
                paths.push_back(p);
            }
            
            vector<vector<int> > right_paths = pathSum(root->right, sum - root->val);
            for (auto v : right_paths) {
                vector<int> p;
                p.push_back(root->val);
                for (auto i = v.begin(); i != v.end(); ++i)
                    p.push_back(*i);
                paths.push_back(p);
            }
        }
        
        return paths;
    }
};
