class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if (s.length() > 15)
            return ret;
        vector<int> ip;
        restoreIpAddresses(s, 0, ip, ret);
        return ret;
    }
    
    void restoreIpAddresses(string &s, int index, vector<int> ip, vector<string> &ret) {
        if (ip.size() == 4 && index == s.length()) {
            stringstream ss;
            ss << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3];
            ret.push_back(ss.str());
            return;
        } else if (index == s.length()) {
            return;
        } else {
            ip.push_back(s[index] - '0');
            restoreIpAddresses(s, index + 1, ip, ret);
            
            if (ip.back() && index + 1 < s.length()) {
                ip.back() = ip.back() * 10 + s[index + 1] - '0';
                restoreIpAddresses(s, index + 2, ip, ret);
            }
            
            if (ip.back() && index + 2 < s.length()) {
                ip.back() = ip.back() * 10 + s[index + 2] - '0';
                if (ip.back() < 256)
                    restoreIpAddresses(s, index + 3, ip, ret);
            }
        }
    }
};
