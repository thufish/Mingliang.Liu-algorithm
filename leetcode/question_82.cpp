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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *p, *q, *t;
        p = q = head;
        t = head = NULL;
        
        while (q != NULL) {
            while (q != NULL && q->val == p->val)
                q = q->next;
            
            // no duplicate node for p
            if (p->next == q) {
                if (t == NULL)
                    t = p;
                else {
                    t->next = p;
                    t = p;
                }
                if (head == NULL)
                    head = t;
            }

            // update the p to next element
            p = q;
        }
        
        // end the new target list
        if (t != NULL)
            t->next = NULL;
        
        return head;
    }
};
