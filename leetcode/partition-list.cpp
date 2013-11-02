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
    ListNode *partition(ListNode *head, int x) {
        ListNode *less = nullptr, *lh = nullptr, *ge = nullptr, *gh = nullptr;
        
        ListNode *p = head;
        while (p) {
            ListNode *q = p;
            p = p->next;
            q->next = nullptr;
            if (q->val < x) {
                if (less)
                    less->next = q;
                less = q;
                if (!lh)
                    lh = less;
            } else {
                if (ge)
                    ge->next = q;
                ge = q;
                if (!gh)
                    gh =  ge;
            }
        }
        
        if (ge)
            ge->next = NULL;
        if (less) {
            less->next = gh;
            return lh;
        } else
            return gh;
    }
};
