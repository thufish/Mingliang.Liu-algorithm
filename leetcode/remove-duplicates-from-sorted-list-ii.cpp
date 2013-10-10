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
        p = head;
        q = head = NULL;
        
        while (p) {
            ListNode *pp = p;
            while (p && p->val == pp->val)
                p = p->next;
            
            if (p == pp->next) {
                if (q)
                    q->next = pp;
                q = pp;
                if (!head)
                    head = q;
            }
        }
        if (q)
            q->next = NULL;
        
        return head;
    }
};
