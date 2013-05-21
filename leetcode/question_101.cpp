// Bonus points if you could solve it both recursively and iteratively.

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
    // Solve this question recursively
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        else
            return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode *node1, TreeNode *node2) {
        if (node1 == NULL && node2 == NULL)
            return true;
        else if (node1 != NULL && node2 != NULL)
            if (node1->val != node2->val)
                return false;
            else
                return isSymmetric(node1->left, node2->right) &&
                       isSymmetric(node1->right, node2->left);
        else
            return false;
    }
};

class Solution2 {
public:
    // Solve this question iteratively
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        // TODO: implement the iterative way!
        
        return true;
    }
};
