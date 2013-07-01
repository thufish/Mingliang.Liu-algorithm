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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head, *q, *p = NULL;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                q = l1;
                l1 = l1->next;
            } else {
                q = l2;
                l2 = l2->next;
            }
            
            if (!p)
                head = p = q;
            else
                p = p->next = q;
        }
        
        q = l1 ? l1 : l2;
        if (!p)
            head = q;
        else
            p->next = q;
        
        return head;
    }
};
