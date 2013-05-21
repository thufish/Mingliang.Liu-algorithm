class Solution {
public:
    // f(n) = f(n - 1) + f(n - 2)
    int climbStairs(int n) {
        int p, q;
        p = 0;
        q = 1;
        
        for (int i = 1; i <= n; i++) {
            q += p;
            p = q - p;
        }
        
        return q;
    }
};
