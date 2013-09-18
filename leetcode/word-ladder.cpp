class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, bool> visited;
        visited[start] = true;
        
        queue<pair<string, int>> Q;
        Q.push({start, 1});
        while (!Q.empty()) {
            const string s = Q.front().first;
            int len = Q.front().second;
            Q.pop();
            
            for (int i = 0; i < s.length(); i++) {
                for (int e = 0; e < 26; e++) {
                    char c = 'a' + e;
                    if (c == s[i])
                        continue;
                        
                    string ss(s);
                    ss[i] = c;
                    if (ss == end)
                        return len + 1;
                    else if (dict.count(ss) && !visited[ss]) {
                        Q.push({ss, len + 1});
                        visited[ss] = true;
                    }
                }
            }
        }
        
        return 0;
    }
};
