#include <algorithm>

using namespace std;

// This is a cheating solution
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        return remove(A, A + n, elem) - A;
    }
};

class Solution2 {
public:
    int removeElement(int A[], int n, int elem) {
        int len = 0;
        int i = 0;
        while (true) {
            while (i < n && A[i] == elem)
                i++;
            if (i >= n)
                break;
            A[len++] = A[i++];
        }
        
        return len;
    }
};
