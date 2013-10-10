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
    ListNode *rotateRight(ListNode *head, int k) {
        // trivial case first
        if (!head)
            return NULL;
        
        int len = 0;
        ListNode *h = head;
        while (h) {
            len++;
            h = h->next;
        }
        k = k % len;

        ListNode *p = head;
        while (k) {
            k--;
            p = p->next;
        }
        ListNode *q = head;
        while (p && p->next) {
            p = p->next;
            q = q->next;
        }
        
        if (p) {
            p->next = head;
            head = q->next;
            q->next = NULL;
        }
        
        return head;
    }
};
