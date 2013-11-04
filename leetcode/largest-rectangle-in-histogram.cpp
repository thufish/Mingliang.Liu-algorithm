/** O(NlgN) solution with devide-and-conquer method */
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        return largestRectangleAreaHelper(height, 0, height.size() - 1);
    }
    
    int largestRectangleAreaHelper(vector<int> &height, int left, int right) {
        if (left == right)
            return height[left];
        else if (left > right)
            return 0;
        
        int mid = left + (right - left) / 2;
        int mleft = largestRectangleAreaHelper(height, 0, mid);
        int mright = largestRectangleAreaHelper(height, mid + 1, right);
        
        int lmin = height[mid];
        int larea = 0;
        for (int i = mid; i >= 0; i--) {
            lmin = min(lmin, height[i]);
            larea = max(larea, lmin * (mid - i + 1));
        }
        
        int rmin = height[mid + 1];
        int rarea = 0;
        for (int i = mid + 1; i <= right; i++) {
            rmin = min(rmin, height[i]);
            rarea = max(rarea, rmin * (i - mid));
        }
        
        return max(larea + rarea, max(mleft, mright));
    }
};

/** The O(n) solution with a stack.
 * @see http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
 */
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> S;
        
        height.push_back(0);
        
        int ret = 0;
        
        int i = 0;
        while (i < height.size()) {
            if (S.empty() || height[i] > height[S.top()])
                S.push(i++);
            else {
                int t = S.top();
                S.pop();
                ret = max(ret, height[t] * (S.empty() ? i : i - S.top() - 1));
            }
        }
        
        return ret;
    }
};
