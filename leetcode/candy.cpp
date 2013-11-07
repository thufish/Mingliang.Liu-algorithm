class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> count(ratings.size(), 1);
        
        int incr = 1;
        for (int i = 1; i < ratings.size(); i++)
            if (ratings[i] > ratings[i - 1])
                count[i] = ++incr;
            else
                incr = 1;
        
        incr = 1;
        for (int i = ratings.size() - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1])
                count[i] = max(count[i], ++incr);
            else
                incr = 1;
        
        int ret = 0;
        for (int c : count)
            ret += c;
        return ret;
    }
};
