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
        vector<int> a;
        vector<vector<int>> ans;
        pathSum(root, sum, a, ans);
        return ans;
    }
    
    void pathSum(TreeNode *root, int sum, vector<int> a, vector<vector<int>> &ans) {
        if (root == NULL)
            return;
        a.push_back(root->val);
        if (root->left == NULL && root->right == NULL && root->val == sum)
            ans.push_back(a);
        else {
            if (root->left)
                pathSum(root->left, sum - root->val, a, ans);
            if (root->right)
                pathSum(root->right, sum - root->val, a, ans);
        }
    }
};
