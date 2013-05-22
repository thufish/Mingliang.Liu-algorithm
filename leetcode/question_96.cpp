class Solution {
public:
    int numTrees(int n) {
        if (n <= 1)
            return 1;
        else if (n == 2)
            return 2;
        else if (n == 3)
            return 5;
        
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += numTrees(i - 1) * numTrees(n - i);
        }
        
        return sum;
    }
};
