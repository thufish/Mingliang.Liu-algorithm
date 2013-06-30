/** This is the naive solution I invented by myself.
 * It's very stupid and very naive.
 *
 * - when a new high bar occurs, calculate the lefter water
 * - There may be bars in the rightmost after the last high bar. Recursive
 *   NOTE: update the last high bar before trapping recursively
 */
class Solution1 {
public:
    int trap(int A[], int n) {
        if (n <= 1)
            return 0;

        int water = 0;
        
        int max_left = 0;
        int index_left = 0;
        
        for (int i = 0; i < n; ++i) {
            if (A[i] >= max_left) { // NOTE: >= instead of >
                for (int j = index_left + 1; j < i; ++j)
                    water += max_left - A[j];
                max_left = A[i];
                index_left = i;
            }
        }
        
        // update the last high bar
        int max_right = 0;
        for (int i = index_left + 1; i < n; ++i)
            if (A[i] > max_right)
                max_right = A[i];
        A[index_left] = max_right;

        return water + trap(A + index_left, n - index_left);
    }
};
