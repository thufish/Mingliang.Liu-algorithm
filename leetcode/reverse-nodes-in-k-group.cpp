/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** Recursive solution */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 0 || k == 1)
            return head;
        
        ListNode *khead = head;
        for (int i = 0; i < k; i++) {
            if (khead)
                khead = khead->next;
            else
                return head;
        }
        
        ListNode *left = reverseKGroup(khead, k);
        ListNode *p = head, *prev = NULL;
        while (p != khead) {
            ListNode *next = p;
            p = p->next;
            next->next = prev ? prev : left;
            prev = next;
        }
        
        return prev;
    }
};

/** Iterative solution */
class Solution1 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 0 || k == 1)
            return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        
        int i = 0;
        while (head) {
            i++;
            if (i % k == 0) {
                p = reverse(p, head->next);
                head = p->next;
            } else {
                head = head->next;
            }
        }
        
        return dummy.next;
    }
    
    ListNode *reverse(ListNode *first, ListNode *last) {
        ListNode *pre = first->next;
        ListNode *cur = pre->next;
        while (cur != last) {
            pre->next = cur->next;
            cur->next = first->next;
            first->next = cur;
            
            cur = pre->next;
        }
        
        return pre;
    }
};
