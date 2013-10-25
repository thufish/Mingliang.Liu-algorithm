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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next)
            return head;
        
        if (head->val == head->next->val) {
            ListNode *p = head;
            int val = head->val;
            while (p && p->val == val) {
                ListNode *q = p;
                p = p->next;
                delete q;
            }
            return deleteDuplicates(p);
        } else {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};
