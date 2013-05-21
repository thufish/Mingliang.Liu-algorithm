class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // backwards
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        // both A and B are non-empty
        while (i >= 0 && j >= 0) {
            while (i >= 0 && A[i] >= B[j])
                A[k--] = A[i--];
            while (j >= 0 && A[i] <= B[j])
                A[k--] = B[j--];
        }
        
        // if A is empty
        if (i < 0)
            while (j >= 0 && k >= 0)
                A[k--] = B[j--];
        // if B is empty, do nothing
    }
};
