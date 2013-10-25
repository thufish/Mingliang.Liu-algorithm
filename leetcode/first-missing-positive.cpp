class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (n < 1)
            return 1;
        
        for (int i = 0; i < n;)
            if (A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[A[i] - 1], A[i]);
            else
                i++;

        int i = 0;
        for (; i < n; i++)
            if (A[i] != i + 1)
                break;
        
        return i + 1;
    }
};
