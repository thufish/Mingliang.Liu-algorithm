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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p, *pp;
        p = pp = head;
        while (pp) {
            p = p->next;
            if (pp->next)
                pp = pp->next->next;
            else
                return nullptr;
            if (p == pp)
                break;
        }
        if (!p || !pp)
            return nullptr;
        
        p = head;
        while (p != pp) {
            p = p->next;
            pp = pp->next;
        }
        
        return p;
    }
};
