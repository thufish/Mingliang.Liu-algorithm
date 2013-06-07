#include <list>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

/** This solution employs the STL.
 * Kind of cheating. But you should remember all the general algorithms
 */
void remove_duplicat1(list<int> &l) {
    l.sort();
    l.unique();
}

/**
 * Use the naive O(N^2) solution
 */
void remove_duplicat2(list<int> &l) {
    for (list<int>::iterator I = l.begin(); I != l.end(); ++I) {
        //NOTE: have a look at this nested loop please !
        list<int>::iterator II = I;
        for (list<int>::iterator J = ++II; J != l.end(); ) {
            list<int>::iterator JJ = J++;
            if (*I == *JJ)
                l.erase(JJ);
        }
    }
}

/**
 * The hash table solution.
 *
 * The hash table is considered to be cheating some cases.
 * However, you should always propose this solution if possible.
 */
void remove_duplicat3(list<int> &l) {
    unordered_set<int> val_set;
    for (list<int>::iterator I = l.begin(); I != l.end(); ) {
        list<int>::iterator II = I++;
        if (val_set.find(*II) != val_set.end()) // found
            l.erase(II);
        else
            val_set.insert(*II);
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
    cout << endl;

    remove_duplicat2(l1);
    dump(l1);

    return 0;
}
