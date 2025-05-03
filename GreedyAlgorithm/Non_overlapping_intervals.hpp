#ifndef NON_OVERLAPPING_INTERVALS_HPP
#define NON_OVERLAPPING_INTERVALS_HPP

#include <vector>
using std::vector;

#include <algorithm>
using std::sort; using std::min;

/**
 * @brief 依旧是判断重叠区间，与用最少数量的箭射爆气球问题一样，eliminate重复区间的次数就是判断有多少个重复区间
 * 如果两个区间重叠，为了得到更多的非重叠区间应该取右边界的最小值
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if(intervals.size() == 1) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            if(lhs[0] == rhs[0]) return lhs[1] < rhs[1];
            return lhs[0] < rhs[0];
        });
        int result = 0;
        for(int cur = 1; cur < intervals.size(); ++cur) {
            if(intervals[cur][0] < intervals[cur-1][1]) {
                ++result;
                intervals[cur][1] = min(intervals[cur-1][1], intervals[cur][1]);
            }
        }
        return result;
    }
};


#endif