class Solution {
public:
    double pow(double x, int n) {
        bool sign = (n < 0);
        
        n = abs(n);
        double power = 1.0;
        double xx = x;
        while (n > 0) {
            if (n % 2)
                power *= xx;
            xx = xx * xx;
            n /= 2;
        }
        
        return sign ? 1 / power : power;
    }
};
