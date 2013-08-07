class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        if (n == 0)
            return {-1, -1};
        else if (n == 1) {
            if (A[0] == target)
                return {0, 0};
            else
                return {-1, -1};
        }
        
        int L = n;
        int R = -1;
        
        int mid, left = 0, right = n - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (A[mid] == target)
                L = min(L, mid);
            if (A[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        left = 0;
        right = n - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (A[mid] == target)
                R = max(R, mid);
            if (A[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        if (L <= R)
            return {L, R};
        else
            return {-1, -1};
    }
};
