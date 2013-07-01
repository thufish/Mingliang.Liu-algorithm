class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // trivial cases first
        if (n <= 1)
            return n;

        int value = A[0], index = 1;
        bool duplicated = false;
        
        for (int i = 1; i < n; ++i) {
            if (A[i] == value) {
                if (!duplicated) {
                    A[index++] = A[i];
                    duplicated = true;
                }
            } else {
                value = A[index++] = A[i];
                duplicated = false;
            }
        }
        
        return index;
    }
};
