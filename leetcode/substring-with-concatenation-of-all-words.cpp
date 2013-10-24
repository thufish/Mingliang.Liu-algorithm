#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> Ans;
        int n = L.size();
        if (0 == n)
            return Ans;
        int len = L[0].size();

        unordered_map <string, int> mapL;
        for (string it : L )
            mapL[it]++;

        int m = S.size();
        unordered_map <string, int> mapMatch;
        for (int offset = 0; offset < len; offset++) {
            mapMatch.clear();
            int left = offset;
            int count = 0;
            for (int right = offset; right + len <= m ; right += len) {
                string str = S.substr(right, len);
                if (mapL.count(str) > 0) {
                    mapMatch[str]++;
                    if (mapMatch.at(str) <= mapL.at(str))
                        count++;

                    if (count == n)
                        Ans.push_back(left);

                    if ((right - left) / len + 1 == n ) {
                        str = S.substr(left, len);
                        mapMatch[str]--;
                        if (mapMatch.at(str) < mapL.at(str))
                            count--;
                        left += len;
                    }
                }
                else {
                    mapMatch.clear();
                    left = right + len;
                    count = 0;
                }
            }
        }

        return Ans;
    }
};
