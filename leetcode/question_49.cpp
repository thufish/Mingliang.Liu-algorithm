#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/** This solution uses the sorted string as key of the map */
class Solution1 {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string>> strmap;
        for (string str : strs) {
            string sstr(str);
            sort(sstr.begin(), sstr.end());
            strmap[sstr].push_back(str);
        }
        
        vector<string> ans;
        for (const auto &sp : strmap)
            if (sp.second.size() > 1)
                ans.insert(ans.end(), sp.second.begin(), sp.second.end());
        
        return ans;
    }
};

/* We can further improve the performance since the string sorting costs
 * O(nlgn) time. We use the compressed string as the key which is O(n).
 * The string is compressed by the number of chars in it,
 * e.g. accccffzzz, zccacfcfzz, zzzffcccca ==> 1a4c2f3z
 */
class Solution2 {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string>> strmap;
        for (string str : strs) {
            vector<int> counts(26, 0);
            for (char c : str)
                counts[c - 'a']++;

            stringstream ss;
            for (int i = 0; i < 26; i++)
                if (counts[i] > 0)
                    ss << counts[i] << (char)('a' + i);
            strmap[ss.str()].push_back(str);
        }
        
        vector<string> ans;
        for (auto &sp : strmap)
            if (sp.second.size() > 1)
                ans.insert(ans.end(), sp.second.begin(), sp.second.end());
        
        return ans;
    }
};
