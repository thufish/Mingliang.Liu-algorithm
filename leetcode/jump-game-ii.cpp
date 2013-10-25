class Solution {
public:
    int jump(int A[], int n) {
        vector<int> jumps(n, 0);
        
        for (int i = 0; i < n; i++)
            for (int j = min(A[i] + i, n - 1); !jumps[j] && j > i; j--)
                jumps[j] = jumps[i] + 1;
        
        return jumps.back();
    }
};
