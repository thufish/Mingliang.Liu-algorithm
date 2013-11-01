class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        if (n < 0)
            return ret;
        else if (n == 0)
            return {0};
        else if (n == 1)
            return {0, 1};
            
        vector<int> prev = grayCode(n - 1);
        int base = 1 << (n - 1);
        ret.reserve(1 << n);
        copy(prev.begin(), prev.end(), back_inserter(ret));
        for (auto i = prev.rbegin(); i != prev.rend(); i++)
            ret.push_back(base + *i);
        
        return ret;
    }
};
