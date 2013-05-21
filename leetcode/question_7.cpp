class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = 0;
        int sign = x >> 31 & 0x1;
        x = x > 0 ? x : -x;
        
        while (x > 0) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        
        if (sign)
            return -ans;
        else
            return ans;
    }
};
