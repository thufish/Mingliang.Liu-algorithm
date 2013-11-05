#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;

    Node(int val) : val(val), next(NULL) {}
};

void dump(struct Node *head, int count) {
    while (count-- >= 0) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "..." << endl;
}

Node* loop_start(Node *l) {
    if (l == NULL || l->next == NULL)
        return NULL;

    // the initial value is important: make p1 != p2
    Node *p1 = l->next;
    Node *p2 = l->next->next;

    // until the first time meet
    while (p2 && p2->next && p2 != p1) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    // no circle at all
    if (!p2 || !p1)
        return NULL;

    p1 = l; // from start
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

int main() {
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node n6(6);
    Node n7(7);
    Node n8(8);
    Node n9(9);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;
    n8.next = &n9;
    n9.next = &n4;

    dump(&n1, 9);
    cout << endl;

    Node *p = loop_start(&n1);
    if (p)
        cout << p->val << endl;

    return 0;
}
