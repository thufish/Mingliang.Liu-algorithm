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

    vector<TreeNode *> generateTrees(int low, int high) {
        vector<TreeNode *> nodes;
        if (low > high)
            nodes.push_back(NULL);
        else if (low == high)
            nodes.push_back(new TreeNode(low));
        else {
            for (int i = low; i <= high; i++) {
                vector<TreeNode *> left = generateTrees(low, i - 1);
                vector<TreeNode *> right = generateTrees(i + 1, high);
                for (TreeNode *l : left)
                    for (TreeNode *r : right) {
                        TreeNode *node = new TreeNode(i);
                        node->left = l;
                        node->right = r;
                        nodes.push_back(node);
                    }
            }
            return nodes;
        }
    }
};
