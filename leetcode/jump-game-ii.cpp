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

/*
 * We use "last" to keep track of the maximum distance that has been reached
 * by using the minimum steps "ret", whereas "curr" is the maximum distance
 * that can be reached by using "ret+1" steps. Thus,
 * curr = max(i+A[i]) where 0 <= i <= last.
 */
class Solution {
public:
    int jump(int A[], int n) {
        int ret = 0;
        int last = 0;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (i > last) {
                last = curr;
                ++ret;
            }
            curr = max(curr, i+A[i]);
        }

        return ret;
    }
};
