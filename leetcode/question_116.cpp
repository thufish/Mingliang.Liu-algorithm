/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *p, *pp;
        pp = root;
        while (pp) {
            p = pp;
            pp = p->left;
            while (p && p->left && p->right) { // NOTE: Ignore the leaf nodes
                p->left->next = p->right;
                p->right->next = p->next ? p->next->left : NULL;
                p = p->next;
            }
        }
    }
};
