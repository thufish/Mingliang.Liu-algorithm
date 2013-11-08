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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *p = head, *pp = nullptr;
        head = nullptr;
        for (int i = 1; p && i < m; i++) {
            pp = p;
            if (!head)
                head = pp;
            p = p->next;
        }
        
        ListNode *rh = nullptr, *rt = nullptr;
        for (int i = 0; p && i < n - m + 1; i++) {
            ListNode *q = p;
            p = p->next;
            q->next = (rh ? rh : nullptr);
            rh = q;
            rt = (rt ? rt : q);
        }
        
        if (pp)
            pp->next = rh;
        if (rt)
            rt->next = p;
        if (!head)
            head = rh;
        
        return head;
    }
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev_m, *prev = &dummy;
        
        for (int i = 1; i <= n; i++) {
            if (i == m)
                prev_m = prev;
            else if (i > m) {
                prev->next = head->next;
                head->next = prev_m->next;
                prev_m->next = head;
                head = prev;
            }
            
            prev = head;
            head = head->next;
        }
        
        return dummy.next;
    }
};
