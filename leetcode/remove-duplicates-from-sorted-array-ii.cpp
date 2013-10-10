class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0)
            return 0;

        int len = 1;
        int i = 1;
        while (i < n) {
            // allow at most twice
            if (A[i] == A[i - 1])
                A[len++] = A[i++];
            // skip more than two dups
            while (i < n && A[i] == A[i - 1])
                i++;
            if (i < n)
                A[len++] = A[i++];
        }
        
        return len;
    }
};
