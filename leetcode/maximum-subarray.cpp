class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (!A || n <= 0)
            return 0;

        int max_so_far = 0;
        int max_sum = A[0];
        for (int i = 0; i < n; i++) {
            max_so_far += A[i];
            max_sum = max(max_so_far, max_sum);
            max_so_far = max(0, max_so_far);
        }
        
        return max_sum;
    }
};

/** The devide-and-conquer solution
 *
 * T(n) = 2 * T(n/2) + O(n)
 */
class Solution2 {
public:
    int maxSubArray(int A[], int n) {
        // trivial cases first
        if (n < 1)
            return 0;
        else if (n == 1)
            return A[0];
        else if (n == 2)
            return max(max(A[0], A[1]), A[0] + A[1]);
        
        int mid = n / 2;
        int max_left = maxSubArray(A, mid);
        int max_right = maxSubArray(A + mid, n - mid);
        
        int max_to_left = INT_MIN;
        int sum_to_left = 0;
        for (int i = mid - 1; i >= 0; --i) {
            sum_to_left += A[i];
            if (sum_to_left > max_to_left)
                max_to_left = sum_to_left;
        }
        int max_to_right = INT_MIN;
        int sum_to_right = 0;
        for (int i = mid; i < n; ++i) {
            sum_to_right += A[i];
            if (sum_to_right > max_to_right)
                max_to_right = sum_to_right;
        }

        return max(max(max_left, max_right), max_to_left + max_to_right);
    }
};
