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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return NULL;
            
        ListNode *head = NULL, *p = NULL;
        while (true) {
            int index = -1;
            int val = INT_MAX;
            for (int i = 0; i < lists.size(); i++)
                if (lists[i] && lists[i]->val < val) {
                    val = lists[i]->val;
                    index = i;
                }
                
            if (index == -1)
                break;
        
            if (p)
                p = p->next = lists[index];
            else
                head = p = lists[index];
            lists[index] = lists[index]->next;
        }
        
        if (p)
            p->next = NULL;
        
        return head;
    }
};
