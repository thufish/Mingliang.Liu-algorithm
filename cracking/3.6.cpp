#include <stack>
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
    s.push(6);

    sort(s);

    while (!s.empty()) {
        cout << s.top() << "\t";
        s.pop();
    }
    cout << endl;

    return 0;
}
