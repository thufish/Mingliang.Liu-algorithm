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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (l1 == NULL && l2 == NULL)
            return NULL;
        
        ListNode *head = NULL;
        ListNode *node = NULL;
        bool carrier = 0;
        
        // adding up two nodes
        while (l1 != NULL && l2 != NULL) {
            int val = l1->val + l2->val + carrier;
            carrier = val / 10;
            val %= 10;
            
            ListNode *new_node = new ListNode(val);
            if (node == NULL) {
                node = head = new_node;
            } else {
                node->next = new_node;
                node = new_node;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        // the nodes left in one list
        while (l1 != NULL) {
            int val = l1->val + carrier;
            carrier = val / 10;
            val %= 10;
            
            ListNode *new_node = new ListNode(val);
            if (node == NULL) {
                node = head = new_node;
            } else {
                node->next = new_node;
                node = new_node;
            }
            
            l1 = l1->next;
        }
        
        while(l2 != NULL) {
            int val = l2->val + carrier;
            carrier = val / 10;
            val %= 10;
            
            ListNode *new_node = new ListNode(val);
            if (node == NULL) {
                node = head = new_node;
            } else {
                node->next = new_node;
                node = new_node;
            }
            
            l2 = l2->next;
        }
        
        // the last node
        if (carrier) {
            ListNode *new_node = new ListNode(1);
            node->next = new_node;
            node = new_node;
        }
        
        return head;
    }
};
