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
        ListNode *head = NULL, *p = NULL;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                if (p)
                    p->next = l1;
                p = l1;
                if (!head)
                    head = p;
                l1 = l1->next;
            } else {
                if (p)
                    p->next = l2;
                p = l2;
                if (!head)
                    head = p;
                l2 = l2->next;
            }
        }
        
        if (l1) {
            if (p)
                p->next = l1;
            p = l1;
            if (!head)
                head = p;
        } else {
            if (p)
                p->next = l2;
            p = l2;
            if (!head)
                head = p;
        }
        
        return head;
    }
};
