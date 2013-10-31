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
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        
        ListNode *p, *pp;
        p = pp = head;
        while (pp) {
            p = p->next;
            if (!pp->next)
                return false;
            pp = pp->next->next;
            if (p == pp)
                return true;
        }
        
        return false;
    }
};
