#include <stack>
#include <iostream>

using namespace std;

template <typename Type>
class stack_with_min {
public:
    void pop() {
        if (elements.empty())
            return;

        Type tmp = elements.top();
        elements.pop();
        if (tmp == min())
            mins.pop();
    }

    void push(Type val) {
        elements.push(val);
        if (val <= min())
            mins.push(val);
    }

    Type top() const {
        return elements.top();
    }

    Type min() const {
        if (mins.empty())
            return INT_MAX;
        else
            return mins.top();
    }

private:
    stack<Type> elements;
    stack<Type> mins;
};

int main() {
    stack_with_min<int> sm;
    sm.push(8);
    cout << sm.min() << "\t";
    sm.push(6);
    cout << sm.min() << "\t";
    sm.push(3);
    cout << sm.min() << "\t";
    sm.push(5);
    cout << sm.min() << "\t";
    sm.push(4);
    cout << sm.min() << "\t";
    sm.push(9);
    cout << sm.min() << "\t";
    sm.push(3);
    cout << sm.min() << "\t";
    sm.pop();
    cout << sm.min() << "\t";
    sm.pop();
    cout << sm.min() << "\t";
    sm.pop();
    cout << sm.min() << "\t";
    sm.pop();
    cout << sm.min() << "\t";
    sm.pop();
    cout << sm.min() << "\t";
    sm.pop();
    cout << sm.min() << "\t";
    sm.pop();
    cout << sm.min() << "\t";
    sm.pop();
    cout << sm.min() << "\t";
    cout << endl;

    return 0;
}
