/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> vals;
        inOrderVisit(root, vals);
        for (int i = 0, j = vals.size() - 1; i < j; i++, j--)
            if (vals[i] != vals[j])
                return false;
        return true;
    }
    
    void inOrderVisit(TreeNode *root, vector<int> &vals) {
        if (root == NULL)
            return;

        inOrderVisit(root->left, vals);
        vals.push_back(root->val);
        inOrderVisit(root->right, vals);
    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (root == NULL)
            return true;
        else
            return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL)
            return true;
        else if (left != NULL && right != NULL)
            return left->val == right->val &&
                   isSymmetric(left->left, right->right) &&
                   isSymmetric(left->right, right->left);
        else
            return false;
    }
};
