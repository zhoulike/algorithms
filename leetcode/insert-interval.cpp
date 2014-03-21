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

        auto iter = intervals.begin();
        while (iter != intervals.end() && iter->start < newInterval.start) {
            ret.push_back(Interval(iter->start, iter->end));
            ++iter;
        }  //find an insertion position 

        if (ret.empty() || ret.back().end < newInterval.start) //empty or no insersection with the previous interval
            ret.push_back(newInterval);
        else
            ret.back().end = max(ret.back().end, newInterval.end);

        while (iter != intervals.end()) {
            if (iter->start <= ret.back().end)  //merge interval
                ret.back().end = max(ret.back().end, iter->end);
            else
                ret.push_back(Interval(iter->start, iter->end));
            ++iter;
        }

        return ret;
    }
};