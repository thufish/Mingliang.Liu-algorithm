class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> r;
        combinationSumHelper(candidates, target, ret, r, 0);
        return ret;
    }
    
    void combinationSumHelper(const vector<int> &candidates, int target, vector<vector<int>> &ret, vector<int> r, int index) 
    {
        if (target == 0) {
            ret.push_back(r);
            return;
        } else  if (target < 0) {
            return;
        } else {
            for (int i = index; i < candidates.size(); i++) {
                r.push_back(candidates[i]);
                combinationSumHelper(candidates, target - candidates[i], ret, r, i);
                r.pop_back();
            }
        }
    }
};
