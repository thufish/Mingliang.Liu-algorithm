class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // trivial cases first
        if (n < 2)
            return n;
            
        int len = 1;
        int i = 1;
        while (true) {
            while (i < n && A[i] == A[len - 1])
                i++;
            if (i >= n)
                break;
            A[len++] = A[i++];
        }
        
        return len;
    }
};

#include <algorithm>

class Solution2 {
public:
    // This is a cheating solution
    int removeDuplicates(int A[], int n) {
        return std::unique(A, A + n) - A;
    }
};
