#include <list>
#include <iostream>

using namespace std;

/** make a new list of the reverse order and find the kth element */
int kth_last1(const list<int> &l, int k) {
    list<int> l2(l.rbegin(), l.rend());
    list<int>::const_iterator I;
    for (I = l2.begin(); k > 0 && I != l2.end(); ++I, --k)
        ;
    if (I != l2.end())
        return *I;
    return 0;
}

/** two running pointers */
int kth_last2(const list<int> &l, int k) {
    list<int>::const_iterator I, J;
    I = J = l.begin();

    for (int i = k; i > 0 && I != l.end(); ++I, --i)
        ;
    if (I == l.end())
        return 0;
    else {
        while (++I != l.end())
            ++J;
        if (J != l.end())
            return *J;
        else
            return 0;
    }
}

/** the size of the list is known */
int kth_last3(const list<int> &l, int k) {
    if (k > l.size() - 1)
        return 0;
    else {
        int i = l.size() - 1 - k;
        list<int>::const_iterator I;
        for (I = l.begin(); i > 0; ++I, --i)
            ;
        return *I;
    }
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

    cout << kth_last1(l1, 4) << endl;
    cout << kth_last2(l1, 4) << endl;
    cout << kth_last3(l1, 4) << endl;

    return 0;
}
