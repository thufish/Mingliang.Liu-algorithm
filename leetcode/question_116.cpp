/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

/** The iterative version */
class Solution1 {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *p, *pp;
        pp = root;
        while (pp && pp->left && pp->right) { // NOTE: Ignore the leaf nodes
            p = pp;
            pp = p->left;
            while (p) {
                p->left->next = p->right;
                p->right->next = p->next ? p->next->left : NULL;
                p = p->next;
            }
        }
    }
};


/** The recursive version */
class Solution2 {
public:
    void connect(TreeLinkNode *root) {
        if (!root || (!root->left && !root->right))
            return;
        root->left->next = root->right;
        if (root->next) 
            root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);
    }
};
