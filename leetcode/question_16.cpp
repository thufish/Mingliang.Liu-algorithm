#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> numbers(num);
        sort(numbers.begin(), numbers.end());

        int ans = numbers[0] + numbers[1] + numbers[2];
        int size = numbers.size();
        for (int i = 0; i < size; ++i) {
            int j = i + 1;
            int k = size - 1;
            while (j < k) {
                int sum = numbers[i] + numbers[j] + numbers[k];
                if (sum == target)
                    return target;
                else if (sum < target) {
                    j++;
                    if (abs(target - sum) < abs(target - ans))
                        ans = sum;
                } else {
                    k--;
                    if (abs(target - sum) < abs(target - ans))
                        ans = sum;
                }
            }
        }

        return ans;
    }
};
