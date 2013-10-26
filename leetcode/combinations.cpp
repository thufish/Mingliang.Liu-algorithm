class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> ret;
        if (n < 1 || k < 0)
            return ret;
        vector<int> a;
        combineHelper(n, k, ret, a, 1);
        return ret;
    }
    
    void combineHelper(int n, int k, vector<vector<int>> &ret, vector<int> &a, int index) {
        if (a.size() == k) {
            ret.push_back(a);
            return;
        } else for (int i = index; i <= n; i++) {
            a.push_back(i);
            combineHelper(n, k, ret, a, i + 1);
            a.pop_back();
        }
    }
};
