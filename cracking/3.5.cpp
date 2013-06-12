#include <stack>
#include <iostream>

using namespace std;

template <typename Type>
class MyQueue {
public:
    void push(Type val) {
        s2.push(val);
        be = val;
    }

    void pop() {
        if (s1.empty())
            move();
        if (!s1.empty())
            s1.pop();
    }

    Type front() {
        if (s1.empty())
            move();
        if (!s1.empty())
            return s1.top();
        else
            return INT_MIN;
    }

    Type back() const {
        if (s1.empty() && s2.empty())
            return INT_MAX;
        else
            return be;
    }

private:
    void move() {
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

private:
    stack<Type> s1;
    stack<Type> s2;

    Type be;
};

int main() {
    MyQueue<int> q;
    q.push(1);
    cout << q.front() << "\t" << q.back() << endl;
    q.push(2);
    cout << q.front() << "\t" << q.back() << endl;
    q.push(3);
    cout << q.front() << "\t" << q.back() << endl;
    q.pop();
    cout << q.front() << "\t" << q.back() << endl;
    q.pop();
    cout << q.front() << "\t" << q.back() << endl;
    q.pop();
    cout << q.front() << "\t" << q.back() << endl;
    q.pop();
    cout << q.front() << "\t" << q.back() << endl;
    q.push(4);
    cout << q.front() << "\t" << q.back() << endl;
    q.push(1);
    cout << q.front() << "\t" << q.back() << endl;
    q.push(2);
    cout << q.front() << "\t" << q.back() << endl;
    q.pop();
    cout << q.front() << "\t" << q.back() << endl;
    q.push(5);
    cout << q.front() << "\t" << q.back() << endl;

    return 0;
}
