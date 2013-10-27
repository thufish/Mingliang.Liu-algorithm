class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty())
            return string();
            
        stack<string> sta;
        for (int i = 0; i < path.length();) {
            while (i < path.length() && path[i] == '/')
                i++;
            int start = i;
            while (i < path.length() && path[i] != '/')
                i++;
            
            string subpath = path.substr(start, i - start);
            if (subpath == "..") {
                if (!sta.empty())
                    sta.pop();
            } else if (subpath == "." || subpath == "") {
                ;
            } else {
                sta.push(subpath);
            }
        }
        
        string ans;
        while (!sta.empty()) {
            ans = sta.top() + "/" + ans;
            sta.pop();
        }
        if (!ans.empty())
            ans.pop_back();
        
        return "/" + ans;
    }
};
