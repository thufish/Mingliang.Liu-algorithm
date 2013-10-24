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
