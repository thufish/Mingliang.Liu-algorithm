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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 1)
            return head;

        ListNode *tail = NULL;
        
        ListNode *p = head;
        head = NULL;
        while (true) {
            ListNode *prev, *ktail = NULL, *khead = NULL;
            int i = 0;
            while (i < k && p) {
                prev = p;
                p = p->next;
                if (!ktail)
                    ktail = prev;
                prev->next = khead;
                khead = prev;
                i++;
            }
            
            if (i == k) {
                if (tail)
                    tail->next = khead;
                else
                    head = khead;
                tail = ktail;
            } else {
                // revert
                if (tail) {
                    while (khead) {
                        ListNode *temp = khead;
                        khead = khead->next;
                        temp->next = tail->next;
                        tail->next = temp;
                    }
                } else {
                    while (khead) {
                        ListNode *temp = khead;
                        khead = khead->next;
                        if (!head) {
                            head = temp;
                            head->next = NULL;
                        } else {
                            temp->next = head;
                            head = temp;
                        }
                    }
                }
                break;
            }
        }
        
        return head;
    }
};

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
