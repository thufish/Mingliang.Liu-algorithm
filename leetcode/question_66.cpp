class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ans;
        
        // trivial cases first
        if (digits.empty()) {
            ans.push_back(1);
            return ans;
        }
    
        bool carry = true;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (!carry)
                break;
            bool new_carry = (digits[i] + carry) / 10;
            digits[i] = (digits[i] + carry) % 10;
            carry = new_carry;
        }
        
        if (carry)
            ans.push_back(1);
        for (int d : digits)
            ans.push_back(d);
        
        return ans;
    }
};
