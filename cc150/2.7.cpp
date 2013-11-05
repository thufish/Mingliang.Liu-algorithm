#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int val;
    Node *next;

    Node(int val) : val(val), next(NULL) {}
};

void dump(const Node *head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

/** the iterative solution */
bool is_palindrome(const Node *l) {
    const Node *p1, *p2;
    p1 = p2 = l;
    stack<const Node *> s;
    while (p2 && p2->next) {
        s.push(p1);
        p1 = p1->next;
        p2 = p2->next->next;
    }
    if (p2)
        p1 = p1->next;

    while (p1) {
        const Node *t = s.top();
        s.pop();
        if (t->val != p1->val)
            return false;
        p1 = p1->next;
    }

    return true;
}

/** the recursive solution */
static bool is_palindrome_recursive(const Node *head, int len, const Node **next) {
    if (head == NULL || len == 0)
        return true;
    else if (len == 1) {
        *next = head->next;
        return true;
    } else if (len == 2) {
        *next = head->next->next;
        return head->val == head->next->val;
    } else {
        if (!is_palindrome_recursive(head->next, len - 2, next) || next == NULL)
            return false;
        if (head->val != (*next)->val)
            return false;
        *next = (*next)->next;
        return true;
    }
}
bool is_palindrome2(const Node *l) {
    const Node *head = l;
    int len = 0;
    while (l) {
        ++len;
        l = l->next;
    }

    const Node *next = new Node(-1);
    return is_palindrome_recursive(head, len, &next);
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
    dump(&n1);
    cout << is_palindrome(&n1) << endl;
    cout << is_palindrome2(&n1) << endl;

    Node m1(1);
    Node m2(2);
    Node m3(3);
    Node m4(4);
    Node m5(5);
    Node m6(4);
    Node m7(3);
    Node m8(2);
    Node m9(1);
    m1.next = &m2;
    m2.next = &m3;
    m3.next = &m4;
    m4.next = &m5;
    m5.next = &m6;
    m6.next = &m7;
    m7.next = &m8;
    m8.next = &m9;
    dump(&m1);
    cout << is_palindrome(&m1) << endl;
    cout << is_palindrome2(&m1) << endl;

    Node k1(1);
    Node k2(2);
    Node k3(2);
    Node k4(1);
    k1.next = &k2;
    k2.next = &k3;
    k3.next = &k4;
    dump(&k1);
    cout << is_palindrome(&k1) << endl;
    cout << is_palindrome2(&k1) << endl;

    return 0;
}
