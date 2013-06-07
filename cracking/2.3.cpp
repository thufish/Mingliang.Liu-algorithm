#include <list>
#include <iostream>

using namespace std;

void rm_here(list<int> &l, list<int>::iterator I) {
    list<int>::iterator prev = I;
    list<int>::iterator next = ++I;
    *prev = *next;
    l.erase(next);
}

void dump(const list<int> &l) {
    for (list<int>::const_iterator I = l.begin(); I != l.end(); ++I)
        cout << *I << " -> ";
    cout << "NULL" << endl;
}

int main() {
    list<int> l1;
    l1.push_back(1);
    l1.push_back(7);
    l1.push_back(7);
    l1.push_back(3);
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(5);
    l1.push_back(6);
    l1.push_back(4);
    l1.push_back(4);
    dump(l1);

    list<int>::iterator I = l1.begin();
    ++I;
    ++I;
    rm_here(l1, I);
    dump(l1);

    return 0;
}
