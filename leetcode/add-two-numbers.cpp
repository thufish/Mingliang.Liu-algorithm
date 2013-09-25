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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l, *head;
        l = head = NULL;
        
        bool carry = false;
        while (l1 && l2) {
            int val = l1->val + l2->val + carry;
            ListNode *p = new ListNode(val % 10);
            carry = val / 10;
            if (l)
                l->next = p;
            l = p;
            if (!head)
                head = l;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1) {
            int val = l1->val + carry;
            ListNode *p = new ListNode(val % 10);
            carry = val / 10;
            if (l)
                l->next = p;
            l = p;
            if (!head)
                head = l;
            l1 = l1->next;
        }
                
        while (l2) {
            int val = l2->val + carry;
            ListNode *p = new ListNode(val % 10);
            carry = val / 10;
            if (l)
                l->next = p;
            l = p;
            if (!head)
                head = l;
            l2 = l2->next;
        }
        
        if (carry) {
            assert(head && l);
            ListNode *p = new ListNode(1);
            l->next = p;
        }
        
        return head;
    }
};
