#include <stack>
#include <iostream>

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
        move(stack1.size(), stack1, stack3, stack2);
    }

    void dump() {
        cout << "[Stack 1] size: ";
        cout << stack1.size() << "\t" << endl;
        cout << "[Stack 2] size: ";
        cout << stack2.size() << "\t" << endl;
        cout << "[Stack 3] size: ";
        cout << stack3.size() << "\t" << endl;
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
    t.dump();
    t.move();
    cout << endl;
    t.dump();

    return 0;
}
