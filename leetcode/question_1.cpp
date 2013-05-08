// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> numbers_sorted(numbers);
        vector<int> ans;

        // sort the numbers
        sort(numbers_sorted.begin(), numbers_sorted.end());
        
        // find the two numbers
        int i = 0, j = numbers_sorted.size() - 1;
        while (i < j) {
            if (numbers_sorted[i] + numbers_sorted[j] == target) {
                vector<int>::iterator ii = find(numbers.begin(), numbers.end(), numbers_sorted[i]);
                ans.push_back(distance(numbers.begin(), ii) + 1);
                vector<int>::iterator jj;
                if (numbers_sorted[i] == numbers_sorted[j])
                    jj = find(ii + 1, numbers.end(), numbers_sorted[j]);
                else
                    jj = find(numbers.begin(), numbers.end(), numbers_sorted[j]);
                ans.push_back(distance(numbers.begin(), jj) + 1);
                break;
            } else if (numbers_sorted[i] + numbers_sorted[j] < target)
                i++;
            else
                j--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
