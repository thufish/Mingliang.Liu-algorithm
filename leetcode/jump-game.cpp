class Solution {
public:
    bool canJump(int A[], int n) {
        int longest = 0;
        for (int i = 0; i < n; i++) {
            if (i > longest)
                return false;
            longest = max(longest, A[i] + i);
        }
        return true;
    }
};
