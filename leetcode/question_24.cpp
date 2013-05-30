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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode *nh = head->next;
        
        ListNode *p = head;
        ListNode *q;
        head = NULL;
        while (p != NULL && p->next != NULL) {
            q = p->next;
            p->next = q->next;
            q->next = p;
            if (head != NULL)
                head->next = q;
            head = p;
            p = p->next;
        }
        
        return nh;
    }
};
