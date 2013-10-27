#include <unordered_map>

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

/** The O(n) time and O(n) space solution with a hash table */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, int> p2id;
        unordered_map<int, RandomListNode *> id2p;
        
        RandomListNode *p = head;
        RandomListNode *nhead = NULL, *ntail = NULL;
        p2id[NULL] = 0;
        id2p[0] = NULL;
        int count = 1;
        while (p) {
            p2id[p] = count;
            RandomListNode *q = new RandomListNode(p->label);
            id2p[count] = q;
            if (!nhead)
                nhead = q;
            if (ntail)
                ntail->next = q;
            ntail = q;
            
            count++;
            p = p->next;
        }
        
        p = head;
        RandomListNode *np = nhead;
        while (p) {
            np->random = id2p[p2id[p->random]];
            p = p->next;
            np = np->next;
        }
        
        return nhead;
    }
};

/** The O(n) time and O(1) space solution */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p = head;
        while (p) {
            RandomListNode *q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        
        p = head;
        while (p) {
            p->next->random = p->random ? p->random->next : NULL;
            p = p->next->next;
        }
        
        RandomListNode *nhead = NULL, *ntail = NULL;
        p = head;
        while (p) {
            if (!nhead)
                nhead = p->next;
            if (ntail)
                ntail->next = p->next;
            ntail = p->next;
            p->next = p->next->next;
            p = p->next;
        }
        
        return nhead;
    }
};
