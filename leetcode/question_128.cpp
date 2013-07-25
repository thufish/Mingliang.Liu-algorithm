#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

/** The naive solution using hashing map holding range */
class Solution1 {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> range;
        int max_len = 1;
        
        for (int i = 0; i < num.size(); ++i) {
            if (range.find(num[i]) != range.end())
                continue;

            range[num[i]] = num[i];
            
            if (range.find(num[i] - 1) != range.end()) {
                int min = range[num[i] - 1];
                int max = num[i];
                range[num[i]] = min;
                range[range[num[i] - 1]] = max;
                if (max - min + 1 > max_len)
                    max_len = max - min + 1;
            }
            
            if (range.find(num[i] + 1) != range.end()) {
                int min = range[num[i]];
                int max = range[num[i] + 1];
                range[range[num[i] + 1]] = min;
                range[range[num[i]]] = max;
                if (max - min + 1 > max_len)
                    max_len = max - min + 1;
            }
        }
        
        return max_len;
    }
};

/** A much smarter solution using hashset */
class Solution2 {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> hashset;
        for (int i : num)
            hashset.insert(i);
        
        int max_len = 0;
        for (int i : num) {
            if (hashset.find(i + 1) != hashset.end())
                continue;
            
            int l = 1;
            int tmp = i - 1;
            while (hashset.find(tmp) != hashset.end()) {
                --tmp;
                ++l;
            }
            if (l > max_len)
                max_len = l;
        }
        
        return max_len;
    }
};

int main() {
    Solution1 S;

    vector<int> v1 = {0};
    assert(S.longestConsecutive(v1) == 1);
    vector<int> v2 = {0,0};
    assert(S.longestConsecutive(v2) == 1);
    vector<int> v3 = {0,-1};
    assert(S.longestConsecutive(v3) == 2);
    vector<int> v4 = {0,0,-1};
    assert(S.longestConsecutive(v4) == 2);
    vector<int> v5 = {1,0,-1};
    assert(S.longestConsecutive(v5) == 3);
    vector<int> v6 = {-1,1,0};
    assert(S.longestConsecutive(v6) == 3);
    vector<int> v7 = {1,2,0,1};
    assert(S.longestConsecutive(v7) == 3);
    vector<int> v8 = {0,0,1,-1};
    assert(S.longestConsecutive(v8) == 3);
    vector<int> v9 = {-1,1,2,0};
    assert(S.longestConsecutive(v9) == 4);
    vector<int> v10 = {100,4,200,1,3,2};
    assert(S.longestConsecutive(v10) == 4);
    vector<int> v11 = {1,3,5,2,4};
    assert(S.longestConsecutive(v11) == 5);
    vector<int> v12 = {0,3,7,2,5,8,4,6,0,1};
    assert(S.longestConsecutive(v12) == 9);
    vector<int> v13 = {9,1,4,7,3,-1,0,5,8,-1,6};
    assert(S.longestConsecutive(v13) == 7);

    return 0;
}
