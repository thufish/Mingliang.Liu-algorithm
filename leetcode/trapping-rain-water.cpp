class Solution {
public:
    /** O(n) solution.
     * For each bar, find the max height bar on the left and right.
     * then for this bar it can hold min(max_left, max_right) - height
     */
    int trap(int A[], int n) {
        vector<int> max_left(n, 0);
        vector<int> max_right(n, 0);
         
        int max_left_curr = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] >= max_left_curr)
                max_left_curr = A[i];
            max_left[i] = max_left_curr;   
        }
        
        int max_right_curr = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (A[i] >= max_right_curr)
                max_right_curr = A[i];
            max_right[i] = max_right_curr;
        }
        
        int water = 0;
        for (int i = 0; i < n; i++)
            water += min(max_left[i], max_right[i]) - A[i];
            
        return water;
    }
};
