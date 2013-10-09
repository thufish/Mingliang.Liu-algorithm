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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size());
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num, unsigned int start, unsigned int end) {
        if (start >= end)
            return NULL;
        
        int mid = (start + end) >> 1;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = sortedArrayToBST(num, start, mid);
        root->right = sortedArrayToBST(num, mid + 1, end);
        return root;
    }
};
