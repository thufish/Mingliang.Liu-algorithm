class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (str == NULL)
            return 0;
            
        int abs = 0;
        int sign = 1;
        
        const char *p = str;
        
        // leading space
        while (*p == ' ')
            p++;
            
        // sign
        if (*p == '-') {
            sign = -1;
            p++;
        } else if (*p == '+')
            p++;
        
        while (isdigit(*p)) {
            // check overflow
            if ((abs == 214748364 && (*p - '7'  > 0)) || abs > 214748364)
                return sign > 0 ? INT_MAX : INT_MIN;
            abs = abs * 10 + *p - '0';
            p++;
        }
        
        return abs * sign;
    }
};
