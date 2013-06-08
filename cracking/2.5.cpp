#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;

    Node(int val) : val(val), next(NULL) {}
};

void dump(const Node *);

/**
 * The 1st digit is at the head of the list
 */
Node* add1(const Node *l, const Node *r) {
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

/**
 * The 1st digit is at the tail of the list
 *
 * Non-destructive solution.
 */
static bool format(Node *l) {
    if (l == NULL)
        return false;
    else {
        bool carrier = format(l->next);
        l->val += carrier;
        carrier = l->val / 10;
        l->val = l->val % 10;
        return carrier;
    }
}
Node* add2(const Node *l, const Node *r) {
    Node *ret;
    Node *sum;
    ret = sum = NULL;

    int len1 = 0;
    const Node *head = l;
    while (head) {
        ++len1;
        head = head->next;
    }

    int len2 = 0;
    head = r;
    while (head) {
        ++len2;
        head = head->next;
    }

    int padding;
    const Node *first, *second;
    if (len1 > len2) {
        first = l;
        second = r;
        padding = len1 - len2;
    } else {
        first = r;
        second = l;
        padding = len2 - len1;
    }

    while (padding-- > 0) {
        Node *p = new Node(first->val);
        if (sum) {
            sum->next  = p;
            sum = p;
        } else
            ret = sum = p;
        first = first->next;
    }

    while (first && second) {
        Node *p = new Node(first->val + second->val);
        if (sum) {
            sum->next = p;
            sum = p;
        } else
            ret = sum = p;
        first = first->next;
        second = second->next;
    }

    // NOTE: the recursive algorithm works from backward
    if (format(ret)) {
        Node *p = new Node(1);
        p->next = ret;
        ret = p;
    }
    return ret;
}

/**
 * The 1st digit is at the tail of the list
 *
 * Destructive solution
 */
static Node *reverse(Node *l) {
    Node *head, *next;
    head = next = NULL;
    while (l) {
        next = l->next;
        l->next = head;
        head = l;
        l = next;
    }

    return head;
}
Node* add3(Node *l, Node *r) {
    // NOTE: the result should also be reversed
    return reverse(add1(reverse(l), reverse(r)));
}

void dump(const Node *head) {
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
    cout << endl << endl;
    dump(add1(&n1, &n4));
    cout << endl;
    dump(add2(&n1, &n4));
    cout << endl;
    dump(add3(&n1, &n4));

    return 0;
}
