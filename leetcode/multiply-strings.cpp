class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans(num1.length() + num2.length() + 1, 0);
        for (int i = num1.length() - 1; i >= 0; i--)
            for (int j = num2.length() - 1; j >= 0; j--)
                ans[i + j + 2] += (num1[i] - '0') * (num2[j] - '0');
                
        // format
        int carry = 0;
        for (int k = ans.size() - 1; k >= 0; k--) {
            int new_carry = (ans[k] + carry) / 10;
            ans[k] = (ans[k] + carry) % 10;
            carry = new_carry;
        }

        string str;
        int k = 0;
        while (k < ans.size() && ans[k] == 0)
            k++;
        if (k == ans.size())
            return "0";
        while (k < ans.size())
            str.push_back(ans[k++] + '0');
        
        return str;
    }
};
