/** Binary search solution
 *
 * This is the very naive solution extending the binary search.
 * But It's not the most naive one since there is a O(n) one.
 */
class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == target)
                return mid;
            else if (A[mid] > target) {
                //if (A[mid] > A[right] && A[right] >= target)
                if (A[mid] > A[right] && target < A[left])
                    left = mid + 1;
                else
                    right = mid - 1;
            } else {
                //if (A[mid]  < A[left] && A[left] <= target)
                if (A[mid] < A[left] && target > A[right])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        
        return -1;
    }
};
