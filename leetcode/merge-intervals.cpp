/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


bool operator<(const Interval &l, const Interval &r) {
    return l.start < r.start;
}   

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<Interval> ans;
        if (intervals.empty())
            return ans;

        Interval interval = intervals.front();
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= interval.end)
                interval.end = max(interval.end, intervals[i].end);
            else {
                ans.push_back(interval);
                interval = intervals[i];
            }
        }
        ans.push_back(interval);
        return ans;
    }
};
