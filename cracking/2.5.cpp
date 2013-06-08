#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;

    Node(int val) : val(val), next(NULL) {}
};

Node* add(Node *l, Node *r) {
    Node *sum, *head;
    sum = head = NULL;
    bool carrier = false;
    while (l && r) {
        Node *p = new Node(l->val + r->val + carrier);
        carrier = p->val / 10;
        p->val = p->val % 10;

        if (sum) {
            sum->next = p;
            sum = p;
        } else
            head = sum = p;

        l = l->next;
        r = r->next;
    }

    // the remaining list
    while (l) {
        Node *p = new Node(l->val + carrier);
        carrier = p->val / 10;
        p->val = p->val % 10;
        if (sum) {
            sum->next = p;
            sum = p;
        } else
            head = sum = p;

        l = l->next;
    }

    while (r) {
        Node *p = new Node(r->val + carrier);
        carrier = p->val / 10;
        p->val = p->val % 10;
        if (sum) {
            sum->next = p;
            sum = p;
        } else
            head = sum = p;

        r = r->next;
    }

    if (carrier) {
        Node *p = new Node(1);
        sum->next = p;
    }

    return head;
}

void dump(Node *head) {
    while (head) {
        cout << head->val << "\t";
        head = head->next;
    }
}

int main() {
    Node n1(7);
    Node n2(1);
    Node n3(6);
    n1.next = &n2;
    n2.next = &n3;

    Node n4(5);
    Node n5(9);
    Node n6(4);
    Node n7(9);
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;

    dump(&n1);
    cout << endl;
    dump(&n4);
    cout << endl;
    dump(add(&n1, &n4));

    return 0;
}
