#pragma once

bool operator<(Interval i1, Interval i2)
{
    return i1.start < i2.start;
}

class Solution {
public:
    std::vector<Interval> merge(std::vector<Interval>& intervals) {
        if(intervals.size() < 2) {
            return intervals;
        }
        std::sort(intervals.begin(), intervals.end());
        std::vector<Interval> result;
        for(size_t i = 1; i < intervals.size(); i++) {
            Interval& i1 = intervals[ i - 1 ];
            Interval& i2 = intervals[ i     ];
            if(i1.end >= i2.start) {
                i2.start = std::min( i1.start, i2.start );
                i2.end = std::max( i1.end, i2.end );
            }
            else {
                result.push_back(i1);
            }
        }
        result.push_back(intervals.back());
        return result;
    }
};