#include <iostream>
#include <limits>
#include <cmath>
#include <cassert>

using namespace std;

int divide(int _dividend, int _divisor) {
    if (_divisor == std::numeric_limits<int>::min())
        return _dividend == _divisor;

    //todo signs
    int sign = (_dividend >> 31) ^ (_divisor >> 31);

    long long dividend = abs((long long)_dividend);
    long long divisor = abs((long long)_divisor);
    if (dividend < divisor)
        return 0;
    
    int ret = 0;

    while (dividend > 0) {
        long long D = divisor;
        int ans = 0;
        while (D <= dividend) {
            if (ans == 0)
                ans = 1;
            else
                ans = ans << 1;
            D = D << 1;
        }
        ret += ans;
        dividend -= D >> 1;
    }
    
    if (sign)
        return -ret;
    else
        return ret;
}

int main() {
    assert(divide(48, 7) == 6);
    assert(divide(49, 7) == 7);
    assert(divide(50, 7) == 7);
    assert(divide(20, 7) == 2);
    assert(divide(21, 7) == 3);
    assert(divide(22, 7) == 3);
    assert(divide(5, 7) == 0);
    assert(divide(7, 7) == 1);
    assert(divide(10, 7) == 1);
    assert(divide(13, 7) == 1);

    assert(divide(-48, 7) == -6);
    assert(divide(49, -7) == -7);
    assert(divide(-50, -7) == 7);
    assert(divide(-20, -7) == 2);
    assert(divide(21, -7) == -3);
    assert(divide(-22, 7) == -3);
    assert(divide(5, -7) == 0);
    assert(divide(7, -7) == -1);
    assert(divide(10, -7) == -1);
    assert(divide(-13, -7) == 1);

    assert(divide(2147483647, 1) == 2147483647);
    assert(divide(-1010369383, -2147483648) == 0);
    assert(divide(-2147483648, 1) == -2147483648);

    return 0;
}
