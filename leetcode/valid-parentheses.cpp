class Solution {
public:
    bool isValid(string s) {
        map<char, char> peers;
        peers[')'] = '(';
        peers['}'] = '{';
        peers[']'] = '[';
        
        stack<char> par;
        
        for (char c : s) {
            switch (c) {
                case '(' : case '{' : case '[' :
                    par.push(c);
                    break;
                case ')' : case '}' : case ']' :
                    if (par.empty() || par.top() != peers[c])
                        return false;
                    par.pop();
                    break;
                default:
                    return false;
            }
        }
        
        return par.empty();
    }
};
