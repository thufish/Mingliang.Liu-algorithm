#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

/**
 * Use the hash map to hold the two sums
 */
class Solution1 {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        unordered_map<int, vector<pair<int, int>>> sums;
        for (int i = 0; i < num.size(); ++i)
            for (int j = i + 1; j < num.size(); ++j)
                if (sums.find(num[i] + num[j]) != sums.end())
                    sums[num[i] + num[j]].push_back({i, j});
                else
                    sums[num[i] + num[j]] = {{i, j}};
                    
        set<vector<int>> ans;
        for (auto I = sums.begin(); I != sums.end(); ++I) {
            auto J = sums.find(target - I->first);
            if (J != sums.end()) {
                for (auto II = I->second.begin(); II != I->second.end(); ++II)
                    for (auto JJ = J->second.begin(); JJ != J->second.end(); ++JJ) {
                        vector<int> v = {II->first, II->second, JJ->first, JJ->second};
                        sort(v.begin(), v.end());
                        if (unique(v.begin(), v.end()) == v.end()) {
                            vector<int> vv = {num[II->first], num[II->second], num[JJ->first], num[JJ->second]};
                            sort(vv.begin(), vv.end());
                            ans.insert(vv);
                        }
                    }
            }
        }
        
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

/**
 * Just like the 3-sum problem
 */
class Solution2 {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        /** sort first */
        sort(num.begin(), num.end());

        /* we can also use the vec.erase(unique(), end) method here */
        set<vector<int>> ans;
        for (int i = 0; i < num.size(); ++i)
            for (int j = i + 1; j < num.size(); ++j) {
                int k = j + 1;
                int m = num.size() - 1;
                while (k < m) {
                    if (num[i] + num[j] + num[k] + num[m] > target)
                        --m;
                    else if (num[i] + num[j] + num[k] + num[m] < target)
                        ++k;
                    else {
                        ans.insert({num[i], num[j], num[k], num[m]});
                        --m;
                        ++k;
                    }
                }
            }
        
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
