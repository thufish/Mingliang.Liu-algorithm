/**
 * Find the minimum interval of any two elements in a BST
 */

#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

int min_interval = numeric_limits<int>::max();

struct Node {
    int val;
    Node *left, *right;

    Node(int val) : val(val) {}

    Node(int val, Node *left, Node *right) : val(val), left(left), right(right) {}
};

inline int min4(int a, int b, int c, int d) {
    cout << a << " " << b << " " << c << " " << d << endl;
    return min(min(a, b), min(c, d));
}

pair<int, int> minInterval(Node *root) {
    if (root == nullptr)
        return {numeric_limits<int>::min(), numeric_limits<int>::max()};
    
    pair<int, int> p1, p2, p = {root->val, root->val};
    if (root->left) {
        p1 = minInterval(root->left);
        min_interval = min(min_interval, root->val - p1.second);
        p.first = p1.first;
    }
    if (root->right) {
        p2 = minInterval(root->right);
        min_interval = min(min_interval, p2.first - root->val);
        p.second = p2.second;
    }

    return p;
}

Node *buildBSTHelper(vector<int> &vec, int low, int high) {
    if (low > high)
        return nullptr;
    int mid = low + (high - low) / 2;
    Node *root = new Node(vec[mid]);
    root->left = buildBSTHelper(vec, low, mid - 1);
    root->right = buildBSTHelper(vec, mid + 1, high);
    return root;
}

Node *buildBST(vector<int> &vec) {
    return buildBSTHelper(vec, 0, vec.size() - 1);
}

int main() {
    int MAX = numeric_limits<int>::max();
    int MIN = numeric_limits<int>::min();
    vector<int> v1 = {1, 4, 6, 9, 100, 120};
    minInterval(buildBST(v1));
    cout << min_interval << endl;
    vector<int> v2 = {1, 4, 6, 9, 100, 120, 121};
    minInterval(buildBST(v2));
    cout << min_interval << endl;
    return 0;
}
