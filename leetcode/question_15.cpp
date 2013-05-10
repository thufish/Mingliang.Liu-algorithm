#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        
        vector<int> numbers(num);
        sort(numbers.begin(), numbers.end());
        int size = numbers.size();
        
        for (int i = 0; i < size; ++i) {
            int j = i;
            int k = size - 1;
            while (j < k) {
                if (j == i || numbers[j] + numbers[k] < (0 - numbers[i]))
                    j++;
                else if (k == i || numbers[j] + numbers[k] > (0 - numbers[i]))
                    k--;
                else {
                    vector<int> v;
                    v.push_back(numbers[i]);
                    v.push_back(numbers[j]);
                    v.push_back(numbers[k]);

                    bool found = false;
                    for (auto a : ans)
                        if (a[0] == v[0] && a[1] == v[1] && a[2] == v[2]) {
                            found = true;
                            break;
                        }
                    if (!found)
                        ans.push_back(v);
                    do j++; while (numbers[j] == numbers[j - 1] && j < size);
                    do k--; while (numbers[k] == numbers[k + 1] && k > 0);
                }
            }
        }
        
        return ans;
    }
};
