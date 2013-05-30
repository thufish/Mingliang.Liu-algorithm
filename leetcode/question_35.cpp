class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n == 0)
            return 0;
        else if (target < A[0])
            return 0;
        else if (target > A[n - 1])
            return n;
        
        // binary search
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] == target)
                return mid;
            else if (A[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return left;
    }
};
