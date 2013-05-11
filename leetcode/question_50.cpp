class Solution {
public:
    double pow(double x, int n) {
        // trivial cases first
        if (x == 1)
            return 1;
        else if (x == -1)
            return abs(n) % 2 ? -1 : 1;
            
        if (n == 0)
            return 1;
        else if (n > 0) {
            double ans = 1;
            double tmp = x;
            while (n > 0) {
                if (n % 2)
                    ans *= x;
                x = x * x;
                n = n >> 1;
            }
            return ans;
        } else if (n < 0) {
            return 1.0 / pow(x, 0 - n);
        }    
    }
};
