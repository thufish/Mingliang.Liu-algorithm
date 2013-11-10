/** O(n) solution.
 * For each bar, find the max height bar on the left and right.
 * then for this bar it can hold min(max_left, max_right) - height
 */
class Solution {
public:
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

/** two meeting pointers
 */
class Solution2 {
public:
    int trap(int A[], int n) {
        int water = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            if (A[i] < A[j]) {
                int k = i + 1;
                while (A[k] <= A[i]) {
                    water += (A[i] - A[k]);
                    k++;
                }
                i = k;
            } else {
                int k = j - 1;
                while (A[k] < A[j]) {
                    water += (A[j] - A[k]);
                    k--;
                }
                j = k;
            }
        }
        return water;
    }
};

/** Split the array at the point of the maximum one and handle the left/right
 * part seprately
 */
class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 0)
            return 0;
            
        int water = 0;
        
        int *m = max_element(A, A + n);
        
        for (int *p = A, peak = 0; p != m; p++)
            if (*p > peak)
                peak = *p;
            else
                water += peak - *p;
                
        for (int *q = A + n - 1, peak = 0; q != m; q--)
            if (*q > peak)
                peak = *q;
            else
                water += peak - *q;
        
        return water;
    }
};


// 用一个栈辅助,小于栈顶的元素压入,大于等于栈顶就把栈里所有小于或
// 等于当前值的元素全部出栈处理掉,计算面积,最后把当前元素入栈
//
// 时间复杂度 O(n),空间复杂度 O(n)
class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 0)
            return 0;
            
        int water = 0;
        
        stack<pair<int, int>> S;
        
        for (int i = 0; i < n; i++) {
            int height = 0;
            while (!S.empty()) {
                int bar = S.top().first;
                int pos = S.top().second;
                
                water += (min(bar, A[i]) - height) * (i - pos - 1);
                height = bar;
                
                if (bar > A[i])
                    break;
                else
                    S.pop();
            }
            S.push({A[i], i});
        }
        
        return water;
    }
};
