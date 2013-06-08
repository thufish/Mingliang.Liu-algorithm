#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;

    Node(int val) : val(val), next(NULL) {}
};

struct Node* partition(struct Node *head, int val) {
    struct Node *p, *ph; // small val lists
    struct Node *q, *qh; // big val lists

    p = ph = q = qh = NULL;

    while (head) {
        if (head->val < val)
            if (p) {
                p->next = head;
                p = head;
            } else
                ph = p = head;
        else
            if (q) {
                q->next = head;
                q = head;
            } else
                qh = q = head;
        head = head->next;
    }

    if (q)
        q->next = NULL;
    if (p)
        p->next = qh;
    return ph;
}

void dump(struct Node *head) {
    while (head) {
        cout << head->val << "\t";
        head = head->next;
    }
}

int main() {
    struct Node n1(3);
    struct Node n2(8);
    struct Node n3(5);
    struct Node n4(4);
    struct Node n5(6);
    struct Node n6(2);
    struct Node n7(1);
    struct Node n8(4);
    struct Node n9(9);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;
    n8.next = &n9;

    dump(&n1);
    cout << endl;

    dump(partition(&n1, 5));

    return 0;
}
