class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> ans;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            int j = i, k = num.size() - 1;
            while (j < k) {
                if (i == j || num[j] + num[k] < (0 - num[i]))
                    j++;
                else if (i == k || num[j] + num[k] > (0 - num[i]))
                    k--;
                else {
                    vector<int> a = {num[i], num[j], num[k]};
                    
                    bool found = false;
                    for (auto aa : ans)
                        if (aa[0] == a[0] && aa[1] == a[1] && aa[2] == a[2]) {
                            found = true;
                            break;
                        }
                    if (!found)
                        ans.push_back(a);
                    
                    do j++; while (num[j] == num[j - 1] && j < num.size());
                    do k--; while (num[k] == num[k + 1] && k > 0);
                }
            }
        }
        return ans;
    }
};
