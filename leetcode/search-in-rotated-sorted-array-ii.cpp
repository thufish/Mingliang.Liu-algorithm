class Solution {
public:
    bool search(int A[], int n, int key) {
        return searchHelper(A, 0, n - 1, key);
    }
    
    bool searchHelper(int A[], int low, int high, int key) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (A[mid] == key)
                return true;
            if (A[low] == A[high])
                return searchHelper(A, low, mid - 1, key) ||
                       searchHelper(A, mid + 1, high, key);
            if (A[low] <= A[mid]) // left is sorted
                if (A[low] <= key && key <= A[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            else
                if (A[mid] <= key && key <= A[high])
                    low = mid + 1;
                else
                    high = mid - 1;
        }
        return false;
    }
};
