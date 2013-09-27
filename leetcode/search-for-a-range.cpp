class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int left = -1, right = -1;
        
        // search for the left range
        int l = 0, h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (A[m] == target)
                left = m;
            if (A[m] >= target)
                h = m - 1;
            else
                l = m + 1;
        }
        
        l = 0; h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (A[m] == target)
                right = m;
            if (A[m] <= target)
                l = m + 1;
            else
                h = m - 1;
        }
        
        return {left, right};
    }
};
