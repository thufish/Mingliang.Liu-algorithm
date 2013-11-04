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
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next)
            return;
        
        ListNode *p = head, *pp = head, *pre = nullptr;
        while (pp) {
            pre = p;
            p = p->next;
            if (pp->next)
                pp = pp->next->next;
            else
                break;
        }
        if (pre)
            pre->next = nullptr;
        
        ListNode *q = nullptr;
        while (p) {
            ListNode *prev = p;
            p = p->next;
            prev->next = q;
            q = prev;
        }
        
        while (q) {
            ListNode *qq = q;
            q = q->next;
            qq->next = head->next;
            head->next = qq;
            head = qq->next;
        }
    }
};
