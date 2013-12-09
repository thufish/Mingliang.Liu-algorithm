class Solution {
public:
    string minWindow(string S, string T) {
        unordered_map<char, int> counts;
        for (char c : T)
            counts[c]++;
        
        unordered_map<char, int> found;
        int total = 0, wnd_start = 0;
        int min_start, min_len = S.length() + 1;
        for (int i = 0; i < S.length(); i++) {
            if (counts[S[i]] > 0) {
                found[S[i]]++;
                if (found[S[i]] <= counts[S[i]])
                    total++;
            }
            if (total == T.size()) {
                while (found[S[wnd_start]] > counts[S[wnd_start]] || counts[S[wnd_start]] == 0) {
                    found[S[wnd_start]]--;
                    wnd_start++;
                }
                if (min_len > (i - wnd_start + 1)) {
                    min_len = i - wnd_start + 1;
                    min_start = wnd_start;
                }
            }
        }
        
        if (min_len > S.length())
            return "";
        else
            return S.substr(min_start, min_len);
    }
};
