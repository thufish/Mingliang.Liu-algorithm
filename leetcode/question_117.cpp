/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

/** See http://discuss.leetcode.com/answer_link/309/ for more information
 */
class Solution {
public:
    // the link of level(i) is the queue of level(i+1)
    void connect(TreeLinkNode * n) {
        while (n) {
            TreeLinkNode * next = NULL; // the first node of next level
            TreeLinkNode * prev = NULL; // previous node on the same level
            for (; n; n = n->next) {
                if (!next) next = n->left ? n->left : n->right;

                if (n->left) {
                    if (prev) prev->next = n->left;
                    prev = n->left;
                }
                if (n->right) {
                    if (prev) prev->next = n->right;
                    prev = n->right;
                }
            }
            n = next; // turn to next level
        }
    }
};
