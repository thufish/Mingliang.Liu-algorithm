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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode *buildTree(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe) {
        if (is > ie || ps > pe)
            return nullptr;
        
        TreeNode *root = new TreeNode(postorder[pe]);
        int mid = is;
        for (; mid <= ie; mid++)
            if (inorder[mid] == postorder[pe])
                break;
        
        root->left = buildTree(inorder, is, mid - 1, postorder, ps, pe - (ie - mid) - 1);
        root->right = buildTree(inorder, mid + 1, ie, postorder, pe - (ie - mid), pe - 1);
        
        return root;
    }
};
