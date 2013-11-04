#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <algorithm>

class Solution {
public:
    void recoverTree(TreeNode *root) {
        vector<TreeNode*> inorder_vec;
        inorderTree(root, inorder_vec);
        
        TreeNode *p = NULL;
        for (int i = 1; !p && i < inorder_vec.size(); i++)
            if (inorder_vec[i]->val < inorder_vec[i - 1]->val)
                p = inorder_vec[i - 1];
        
        TreeNode *q = NULL;
        for (int i = inorder_vec.size() - 2; !q && i >= 0; i--)
            if (inorder_vec[i]->val > inorder_vec[i + 1]->val)
                q = inorder_vec[i + 1];
        
        swap(p->val, q->val);
    }
    
    void inorderTree(TreeNode *root, vector<TreeNode*> &inorder_vec) {
        if (!root)
            return;
        
        inorderTree(root->left, inorder_vec);
        inorder_vec.push_back(root);
        inorderTree(root->right, inorder_vec);
    }
};

int main() {
    TreeNode *root = new TreeNode(0);
    TreeNode *left = new TreeNode(1);
    root->left = left;

    Solution S;
    S.recoverTree(root);

    cout << root->val  << root->left->val << endl;

    return 0;
}
