class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> ans;
        int size = 1 << S.size();
        for (int i = 0; i < size; i++) {
            vector<int> a;
            int k = i;
            for (int j = 0; j < S.size() && k; j++, k = k >> 1)
                if (k % 2)
                    a.push_back(S[j]);
            ans.push_back(a);
        }
        return ans;
    }
};

/// This solution uses the recursive method to select the elements
/// The final trick here is when to add the current answer (index == S.size())
class Solution2 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> subsets;
        if (S.size() == 0)
            return subsets;

        sort(S.begin(), S.end());
        vector<int> subset;
        subsetsRecursive(subsets, S, subset, 0);
        
        return subsets;
    }
    
    void subsetsRecursive(vector<vector<int>> &subsets, vector<int> &S, vector<int> subset, int index) {
        if (index == S.size()) {
            // Add the current answer
            sort(subset.begin(), subset.end());
            subsets.push_back(subset);
            return;
        }
        
        // Don't add S[index]
        subsetsRecursive(subsets, S, subset, index + 1);
        
        // Add S[index]
        subset.push_back(S[index]);
        subsetsRecursive(subsets, S, subset, index + 1);
    }
};
