/** A very naive solution using DP backward.
 *
 * This can NOT pass the large dataset because of the time limit
 */
class Solution1 {
public:
    bool canJump(int A[], int n) {
        if (n <= 0)
            return false;

        vector<bool> Jump(n, false);
        Jump[n - 1] = true;
        
        for (int i = n - 2; i >=0; --i)
            for (int j = i + 1; !Jump[i] && j <= i + A[i] && j < n; ++j)
                Jump[i] = Jump[j];
        
        return Jump[0];
    }
};

/** A clever way to keep the fast distance
 */
class Solution2 {
public:
    bool canJump(int A[], int n) {
        if (n <= 0)
            return false;

        int fast = 1;
        for (int i = n - 2; i >= 0; --i)
            fast = fast > A[i] ? fast + 1 : 1;
        
        return fast == 1;
    }
};
