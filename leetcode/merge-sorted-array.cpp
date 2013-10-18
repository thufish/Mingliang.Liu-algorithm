class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int *C = A + m + n - 1;
        while (m > 0 && n > 0) {
            if (A[m - 1] > B[n - 1])
                *C-- = A[--m];
            else
                *C-- = B[--n];
        }
        while (n > 0)
            *C-- = B[--n];
    }
};
