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
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr)
            return nullptr;

        ListNode dummy(0);
        
        while (head) {
            ListNode *p = dummy.next, *pre = &dummy;
            while (p && p->val < head->val) {
                pre = p;
                p = p->next;
            }
            pre->next = head;
            head = head->next;
            pre->next->next = p;
        }
        
        return dummy.next;
    }
};
