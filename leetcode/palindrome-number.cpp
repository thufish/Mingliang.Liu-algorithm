class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int base = 1;
        while (x / base >= 10)
            base *= 10;
        int dase = 1;
        while (base > dase) {
            int a = x / base;
            int b = x / dase;
            if ((a % 10) != (b % 10))
                return false;
            base /= 10;
            dase *= 10;
        }
        return true;
    }
};
