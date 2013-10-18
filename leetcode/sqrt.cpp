#include <cassert>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if (x <= 0)
            return 0;

        int low = 0, high = x;
        while (low <= high) {
            long long  mid = low + (high - low) / 2;
            long long square = mid * mid;
            if (square == x)
                return mid;
            else if (square < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low - 1;
    }
};

int main() {
    Solution S;
    assert(S.sqrt(1) == 1);
    assert(S.sqrt(2) == 1);
    assert(S.sqrt(4) == 2);
    assert(S.sqrt(10) == 3);
    assert(S.sqrt(1000) == 31);
    assert(S.sqrt(2147395599) == 46339);
    assert(S.sqrt(2147483647) == 46340);
    return 0;
}
