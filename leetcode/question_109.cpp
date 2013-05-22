/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

using namespace std;

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)
            return NULL;
            
        ListNode *tail = head;
        while (tail->next)
            tail = tail->next;
        
        return sortedListToBST(head, tail);
    }
    
    TreeNode *sortedListToBST(ListNode *start, ListNode *end) {
        if (start == NULL || end == NULL)
            return NULL;
        else if (start == end)
            return new TreeNode(start->val);
        
        ListNode *p, *pp, *q;
        pp = NULL;
        p = start;
        q = start->next;
        while (p && p != end && q && q != end) {
            pp = p;
            p = p->next;
            q = q->next;
            if (q && q != end)
                q = q->next;
            else
                break;
        }
        
        TreeNode *root = new TreeNode(p->val);
        root->left = sortedListToBST(start, pp);
        root->right = sortedListToBST(p->next, end);
    }
};
