/** Find the kth smallest element of an unsorted vector */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

template<typename T>
size_t partition(vector<T> &vec, size_t first, size_t last) {
    if (first == last || first == last - 1)
        return first;

    size_t part = first;
    // TODO median3(first, middle, last)
    for (size_t curr = first; curr < last; ++curr)
        if (vec[curr] < vec[first])
            swap(vec[curr], vec[++part]);
    swap(vec[part], vec[first]);
    return part;
}

template<typename T>
T topk(vector<T> vec, size_t k) {
    assert(k > 0 && "The K must be a positive number!");
    assert(k <= vec.size() && "The K must be less than vector.size!");

    size_t first = 0, last = vec.size();
    while (first < last) {
        size_t part = partition(vec, first, last);
        if (part - first == k - 1) // found the number
            return vec[part];
        else if (part - first > k - 1)
            last = part;
        else {
            k -= part - first + 1;
            first = part + 1;
        }
    }
    assert("Unreachable");
}

int main() {
    vector<int> a = {10, 20, 30, 40};
    do {
        for (int i = 1; i <= 4; i++)
            assert(topk(a, i) == 10 * i);
    } while (next_permutation(a.begin(), a.end()));

    vector<int> b = {40, 50, 60, 20, 10, 30, 70};
    do {
        for (int i = 1; i <= 7; i++)
            assert(topk(b, i) == 10 * i);
    } while (next_permutation(b.begin(), b.end()));

    return 0;
}
