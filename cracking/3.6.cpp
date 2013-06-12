#include <stack>
#include <cassert>
#include <iostream>

using namespace std;

template <typename Type>
void sort(stack<Type> &s) {
    stack<Type> tmp;
    while (!s.empty()) {
        Type val = s.top();
        s.pop();
        while (!tmp.empty() && tmp.top() > val) {
            s.push(tmp.top());
            tmp.pop();
        }
        tmp.push(val);
    }

    s = tmp;
}

int main() {
    stack<int> s;
    s.push(3);
    s.push(5);
    s.push(1);
    s.push(2);
    s.push(9);
    s.push(8);
    s.push(6);
    s.push(7);
    s.push(4);
    s.push(8);

    sort(s);

    assert(s.top() == 9);
    s.pop();
    assert(s.top() == 8);
    s.pop();
    assert(s.top() == 8);
    s.pop();
    assert(s.top() == 7);
    s.pop();
    assert(s.top() == 6);
    s.pop();
    assert(s.top() == 5);
    s.pop();
    assert(s.top() == 4);
    s.pop();
    assert(s.top() == 3);
    s.pop();
    assert(s.top() == 2);
    s.pop();
    assert(s.top() == 1);
    s.pop();

    cout << "All Passed!" << endl;
    return 0;
}
