#ifndef MERGE_INTERVALS_HPP
#define MERGE_INTERVALS_HPP

#include <vector>
using std::vector;

#include <algorithm>
using std::max; using std::sort;

/**
 * @brief 合并重叠的区间，如果一个区间的右边界等下一个区间的左边界，也属于存在重叠部分
 * @details 使用vector<vector<int>>存放合并后的区间结果，因为之后插入到最后，不会插入到中间部分，因此使用vector就足够了
 * 首先根据左边界进行排序 -> 把第一个区间放入结果中，从第二个区间进行遍历 -> 只要当前区间的左边界小于等于结果集中最后区间的右边界
 * 就更新结果集中的区间右边界，使用最大值，如果没有重叠，就直接插入到结果集中
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if(intervals.size() == 1) return intervals;

        sort(intervals.begin(), intervals.end(), 
             [](const vector<int> &a, const vector<int> &b) -> bool
             {
                if(a[0] == b[0]) return a[1] < b[1];
                else return a[0] < b[0];
        });
        vector<vector<int>> result = {intervals[0]};

        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] <= result.back()[1]) {
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            } else  
                result.push_back(intervals[i]);
        }

        return result;
    }
};

#endif