class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        bool sign = x >> 31 & 0x1;
        x = abs(x);
        while (x) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        
        return sign ? -ret : ret;
    }
};
