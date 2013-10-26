/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        bool taken = false;
     
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].end < newInterval.start)
                ret.push_back(intervals[i]);
            else if (intervals[i].start > newInterval.end) {
                if (!taken) {
                    ret.push_back(newInterval);
                    taken = true;
                }
                ret.push_back(intervals[i]);
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        if (!taken)
            ret.push_back(newInterval);
        
        return ret;
    }
};
