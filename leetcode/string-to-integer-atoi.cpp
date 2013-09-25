class Solution {
public:
    int atoi(const char *str) {
        int ret = 0;
        bool sign = false;
        
        // skip leading spaces
        while (*str == ' ')
            str++;
        
        // the sign char
        if (*str == '+' || *str == '-') {
            if (*str == '-')
                sign = true;
            str++;
        }
        
        while (*str >= '0' && *str <= '9') {
            if (ret > 214748364)
                // must overflow
                return sign ? INT_MIN : INT_MAX;
            
            if (ret == 214748364) {
                // may overflow
                if (!sign && (*str - '0' >= 7))
                    return INT_MAX;
                else if (sign && (*str - '0' >= 8))
                    return INT_MIN;
            }
            // never overflow
            ret = ret * 10 + (*str - '0');
            str++;
        }
        
        return sign ? -ret : ret;
    }
};
