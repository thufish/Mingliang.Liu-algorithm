class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = true;
        vector<int> ans;
        for (int i = digits.size() - 1; i >= 0; i--) {
            ans.push_back((digits[i] + carry) % 10);
            carry = (digits[i] + carry) / 10;;
        }
        if (carry)
            ans.push_back(1);
        return vector<int>(ans.rbegin(), ans.rend());
    }
};
