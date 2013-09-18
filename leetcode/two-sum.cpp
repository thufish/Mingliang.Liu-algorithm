class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> numbers_sorted(numbers);
        sort(numbers_sorted.begin(), numbers_sorted.end());
        
        int index1 = 0, index2 = numbers_sorted.size() - 1;
        while (index1 < index2) {
            int sum = numbers_sorted[index1] + numbers_sorted[index2];
            if (sum == target) {
                int i1 = distance(numbers.begin(), find(numbers.begin(), numbers.end(), numbers_sorted[index1])) + 1;
                int i2 = distance(numbers.begin(), find(numbers.rbegin(), numbers.rend(), numbers_sorted[index2]).base());
                return {min(i1, i2), max(i1, i2)};
            }
            else if (sum < target)
                index1++;
            else
                index2--;
        }
        
        return {0, 0};
    }
};
