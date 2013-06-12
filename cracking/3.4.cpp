#include <stack>
#include <iostream>
#include <cassert>

using namespace std;

template <typename Type>
class Tower {
public:
    template <typename ForwardIterator>
    void init(ForwardIterator start, ForwardIterator end) {
        for (; start != end; ++start)
            stack1.push(*start);
    }

    void move() {
        assert(stack1.size() > 0 && stack2.size() == 0 && stack3.size() == 0);
        move(stack1.size(), stack1, stack3, stack2);
        assert(stack1.size() == 0 && stack2.size() == 0 && stack3.size() > 0);
    }

private:
    void move(int n, stack<Type> &src, stack<Type> &dest, stack<Type> &buf) {
        if (n < 1)
            return;
        else if (n == 1) {
            dest.push(src.top());
            src.pop();
        } else {
            move(n - 1, src, buf, dest);
            dest.push(src.top());
            src.pop();
            move(n - 1, buf, dest, src);
        }
    }
            
private:
    stack<Type> stack1;
    stack<Type> stack2;
    stack<Type> stack3;
};

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Tower<int> t;
    t.init(a, a + 9);
    t.move();

    cout << "All Passed!" << endl;
    return 0;
}
