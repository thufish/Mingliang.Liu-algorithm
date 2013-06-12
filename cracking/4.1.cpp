#include <algorithm>
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

template <typename Type>
struct tree_node {
    Type val;
    tree_node *left;
    tree_node *right;

    tree_node(Type val, tree_node *left = 0, tree_node *right = 0) :
        val(val), left(left), right(right) {}
};

template <typename Type>
bool isBalanced(tree_node<Type> *root) {
    if (isBalancedHelper(root) == -1)
        return false;
    else
        return true;
}

template <typename Type>
static int isBalancedHelper(tree_node<Type> *root) {
    if (!root)
        return 0;

    int l = isBalancedHelper(root->left);
    if (l == -1)
        return -1;
    int r = isBalancedHelper(root->right);
    if (r == -1)
        return -1;

    if (abs(l - r) > 1)
        return -1;
    return max(l, r) + 1;
}

int main() {
    tree_node<int> *t9 = new tree_node<int>(9);
    tree_node<int> *t8 = new tree_node<int>(8);
    tree_node<int> *t7 = new tree_node<int>(7, t8, t9);
    tree_node<int> *t6 = new tree_node<int>(6);
    tree_node<int> *t5 = new tree_node<int>(5);
    tree_node<int> *t4 = new tree_node<int>(4, t5, t6);
    tree_node<int> *t3 = new tree_node<int>(3, t7);
    tree_node<int> *t2 = new tree_node<int>(2, t4);
    tree_node<int> *t1 = new tree_node<int>(1, t2, t3);

    assert(isBalanced(t9));
    assert(isBalanced(t8));
    assert(isBalanced(t7));
    assert(isBalanced(t6));
    assert(isBalanced(t5));
    assert(isBalanced(t4));
    assert(!isBalanced(t3));
    assert(!isBalanced(t2));
    assert(!isBalanced(t1));

    cout << "All Passed!";
    return 0;
}
