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
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }
    
    vector<TreeNode *> generateTrees(int start, int end) {
        vector<TreeNode *> trees;
        if (start <= 0 || start > end) {
            trees.push_back(NULL);
            return trees;
        } else if (start == end) {
            trees.push_back(new TreeNode(start));
            return trees;
        }
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode *> lefts = generateTrees(start, i - 1);
            vector<TreeNode *> rights = generateTrees(i + 1, end);
            for (TreeNode *l : lefts)
                for (TreeNode *r : rights) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    trees.push_back(root);
                }
        }
        
        return trees;
    }
};
