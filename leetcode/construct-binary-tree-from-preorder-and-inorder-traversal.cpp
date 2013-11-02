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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode *buildTree(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie) {
        if (ps > pe || is > ie)
            return nullptr;
        
        TreeNode *root = new TreeNode(preorder[ps]);
        int mid = is;
        for (; mid <= ie; mid++)
            if (inorder[mid] == preorder[ps])
                break;
        root->left = buildTree(preorder, ps + 1, ps + (mid - is), inorder, is, mid - 1);
        root->right = buildTree(preorder, ps + (mid - is) + 1, pe, inorder, mid + 1, ie);
        
        return root;
    }
};
