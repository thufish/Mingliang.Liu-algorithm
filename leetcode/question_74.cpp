class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // search for row
        int left = 0, right = matrix.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        if (left >= matrix.size())
            left = matrix.size() - 1;
        while (left >= 0 && matrix[left][0] > target)
            --left;
        if (left < 0)
            return false;

        int row = left;
        left = 0;
        right = matrix[row].size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return false;  
    }
};
