class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> visited;
        unordered_map<string, vector<string>> parents;
        unordered_set<string> current, next;

        bool found = false;
        current.insert(start);
        while (!current.empty() && !found) {
            for (string s : current)
                visited.insert(s);
            
            for (string str : current)
                for (int i = 0; i < str.length(); i++) {
                    string nstr(str);
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == str[i])
                            continue;
                        nstr[i] = c;
                        
                        if (nstr == end)
                            found = true;
                            
                        if (!visited.count(nstr) && (dict.count(nstr) || nstr == end)) {
                            next.insert(nstr);
                            parents[nstr].push_back(str);
                        }
                    }
                }
            
            current.clear();
            swap(current, next);
        }
        
        vector<vector<string>> ret;
        if (found) {
            vector<string> path;
            buildPath(parents, start, end, path, ret);
        }
        
        return ret;
    }
    
    void buildPath(unordered_map<string, vector<string>> &parents, string start, string end, vector<string> path, vector<vector<string>> &ret) {
        path.push_back(end);
        if (start == end)
            ret.push_back(vector<string>(path.rbegin(), path.rend()));
        else {
            for (string s : parents[end])
                buildPath(parents, start, s, path, ret);
        }
        path.pop_back();
    }
};
