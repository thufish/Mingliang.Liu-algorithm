#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <cassert>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> visited;
        visited.insert(start);
        
        queue<std::pair<string, int>> Q;
        Q.push({start, 1});
        
        while (!Q.empty()) {
            std::pair<string, int> q = Q.front();
            Q.pop();
            
            for (int c = 0; c < q.first.length(); c++)
                for (int e = 0; e < 26; e++) {
                    string tmp(q.first);
                    tmp[c] = 'a' + e;
                    if (tmp == end) // found the end item
                        return q.second + 1;
                    else if (tmp == q.first)
                        continue;
                    else if (dict.find(tmp) != dict.end() &&
                             visited.find(tmp) == visited.end()) {
                        Q.push({tmp, q.second + 1});
                        visited.insert(tmp);
                    }
                }
        }
        
        return 0;
    }
};

int main() {
    Solution S;
    unordered_set<string> dict2 = {"hot","cog","dot","dog","hit","lot","log"};
    cout << S.ladderLength("hot", "cog", dict2) << endl;
    return 0;
}
