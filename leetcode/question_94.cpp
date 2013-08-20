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

    /** The iterative approach in a straight-forward way */
    void inorderTraversalIterative2(TreeNode *root, vector<int> &vec) {
        if (root == NULL)
            return;
            
        stack<pair<TreeNode *, bool>> s;
        s.push(make_pair(root, false));
         
        while (!s.empty()) {
            auto p = s.top();
            s.pop();
            
            // the left child is visited
            if (p.second) {
                vec.push_back(p.first->val);
                if (p.first->right)
                    s.push(make_pair(p.first->right, false));
            } else {
                s.push(make_pair(p.first, true));
                // go to the left child
                if (p.first->left)
                    s.push(make_pair(p.first->left, false));
            }
         }
     }
};
