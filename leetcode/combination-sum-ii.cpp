class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int>> ret;
        vector<int> a;
        combinationSum2Helper(num, target, ret, a, 0);
        return ret;
    }
    
    void combinationSum2Helper(const vector<int> &num, int target, vector<vector<int>> &ret, vector<int> a, int index)
    {
        if (target == 0) {
            ret.push_back(a);
            return;
        } else if (target < 0) {
            return;
        } else {
            for (int i = index; i < num.size(); i++)
                if (i == index || num[i] != num[i - 1]) {
                    a.push_back(num[i]);
                    combinationSum2Helper(num, target - num[i], ret, a, i + 1);
                    a.pop_back();
                }
        }
    }
};
