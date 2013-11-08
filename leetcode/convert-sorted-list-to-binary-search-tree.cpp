/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> num;
        while (head != NULL) {
            num.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(num, 0, num.size());
    }
        
    TreeNode *sortedArrayToBST(vector<int> &num, unsigned int start, unsigned int end) {
        if (start >= end)
            return NULL;
        
        int mid = (start + end) >> 1;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = sortedArrayToBST(num, start, mid);
        root->right = sortedArrayToBST(num, mid + 1, end);
        return root;
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
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode *p = head;
        int len = 0;
        while (p) {
            p = p->next;
            len++;
        }
        return sortedListToBST(head, 0, len - 1);
    }
    
private:
    TreeNode *sortedListToBST(ListNode *&list, int start, int end) {
        if (!list || start > end)
            return nullptr;
        
        int mid = start + (end - start) / 2;
        TreeNode *left = sortedListToBST(list, start, mid - 1);
        TreeNode *root = new TreeNode(list->val);
        root->left = left;
        list = list->next;
        root->right = sortedListToBST(list, mid + 1, end);
        
        return root;
    }
};
