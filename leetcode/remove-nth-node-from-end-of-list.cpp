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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p = head;
        while (--n)
            p = p->next;
        
        ListNode *prev = NULL, *q = head;
        while (p && p->next) {
            p = p->next;
            prev = q;
            q = q->next;
        }
        
        if (prev) {
            prev->next = q->next;
            delete q;
        } else {
            delete head;
            head = q->next;
        }
        
        return head;
    }
};
