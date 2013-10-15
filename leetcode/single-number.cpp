class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n < 1)
            return 0;

        int num = A[0];
        for (int i = 1; i < n; i++)
            num ^= A[i];
            
        return num;
    }
};
