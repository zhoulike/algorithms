/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval i1, Interval i2)
{
    if (i1.start < i2.start)
        return true;
    else
        return false;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), cmp);
        for (auto iter = intervals.begin(); iter != intervals.end();) {
            ret.push_back(Interval(iter->start, iter->end));
            auto next = iter + 1;
            while (next != intervals.end() && next->start <= ret.back().end) {
                ret.back().end = max(ret.back().end, next->end);
                ++next;
            }

            iter = next;
        }

        return ret;
    }

    //same solution, different code
    vector<Interval> merge2(vector<Interval> &intervals) {
        vector<Interval> ret;
        if (intervals.size() == 0)
            return ret;

        sort(intervals.begin(), intervals.end(), cmp);
        ret.push_back(Interval(intervals.front().start, intervals.front().end));
        for (auto iter = intervals.begin() + 1; iter != intervals.end(); ++iter) {
            if (iter->start <= ret.back().end)
                ret.back().end = max(ret.back().end, iter->end);
            else
                ret.push_back(Interval(iter->start, iter->end));
        }

        return ret;
    }
};