class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i = num.size() - 1;
        while (i > 0 && num[i] <= num[i - 1])
            i--;
        if (i == 0) {
            sort(num.begin(), num.end());
        } else {
            int j = num.size() - 1;
            while (j >= i && num[j] <= num[i - 1])
                j--;
            swap(num[j], num[i - 1]);
            for (int k = num.size() - 1; k > i; i++, k--)
                swap(num[i], num[k]);
        }
    }
};
