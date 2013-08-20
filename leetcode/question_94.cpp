#include <vector>
#include <stack>

#define NULL nullptr

/** Definition for binary tree */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {        
        vector<int> ret;
        inorderTraversalRecursive(root, ret);
        return ret;
    }
    
    /** This is the very naive recursive solution */
    void inorderTraversalRecursive(TreeNode *root, vector<int> &vec) {
        if (root == NULL)
            return;
        
        if (root->left != NULL)
            inorderTraversalRecursive(root->left, vec);
        vec.push_back(root->val);
        if (root->right != NULL)
            inorderTraversalRecursive(root->right, vec);
    }

    /** The iterative approach */
    void inorderTraversalIterative(TreeNode *root, vector<int> &vec) {
        if (root == NULL)
            return;

        stack<TreeNode *> s;
        while (!s.empty() || root != NULL) {
            while (root != NULL) {
                s.push(root);
                root = root->left;
            }
            if (!s.empty()) {
                root = s.top();
                s.pop();
                vec.push_back(root->val);
                root = root->right;
            }
        }
    }
};
