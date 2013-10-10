/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode *p, *q;
        q = head;
        p = head->next;
        while (p) {
            while (p && p->val == q->val)
                p = p->next;
            q->next = p;
            q = p;
        }
        
        return head;
    }
};
