class Solution {
public:
    string addBinary(string a, string b) {
        vector<bool> ans;
        
        bool carrier = false;
        int i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 && j >= 0) {
            bool new_carrier = (a[i] - '0' + b[j] - '0' + carrier) / 2;
            ans.push_back((a[i] - '0' + b[j] - '0' + carrier) % 2);
            carrier = new_carrier;
            i--;
            j--;
        }
        while (i >= 0) {
            bool new_carrier = (a[i] - '0' + carrier) / 2;
            ans.push_back((a[i] - '0' + carrier) % 2);
            carrier = new_carrier;
            i--;
        }
        while (j >= 0) {
            bool new_carrier = (b[j] - '0' + carrier) / 2;
            ans.push_back((b[j] - '0' + carrier) % 2);
            carrier = new_carrier;
            j--;
        }
        if (carrier)
            ans.push_back(true);
        
        string ret;
        for (int i = ans.size() - 1; i >= 0; i--)
            ret.push_back(ans[i] + '0');
            
        return ret;
    }
};
