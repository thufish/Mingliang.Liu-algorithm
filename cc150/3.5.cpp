#include <stack>
#include <cassert>
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
            return -1;
    }

    Type back() const {
        if (s1.empty() && s2.empty())
            return -1;
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
    assert(q.front() == 1 && q.back() == 1);
    q.push(2);
    assert(q.front() == 1 && q.back() == 2);
    q.push(3);
    assert(q.front() == 1 && q.back() == 3);
    q.pop();
    assert(q.front() == 2 && q.back() == 3);
    q.pop();
    assert(q.front() == 3 && q.back() == 3);
    q.pop();
    assert(q.front() == -1 && q.back() == -1);
    q.pop();
    assert(q.front() == -1 && q.back() == -1);
    q.push(4);
    assert(q.front() == 4 && q.back() == 4);
    q.push(1);
    assert(q.front() == 4 && q.back() == 1);
    q.push(2);
    assert(q.front() == 4 && q.back() == 2);
    q.pop();
    assert(q.front() == 1 && q.back() == 2);
    q.push(5);
    assert(q.front() == 1 && q.back() == 5);

    cout << "All Passed!" << endl;
    return 0;
}
