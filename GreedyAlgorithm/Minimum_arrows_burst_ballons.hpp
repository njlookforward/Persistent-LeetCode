#ifndef MINIMUM_ARROWS_BURST_BALLONS_HPP
#define MINIMUM_ARROWS_BURST_BALLONS_HPP

#include <vector>
using std::vector;

#include <algorithm>
using std::min; using std::sort;

/**
 * @brief 用最少数量的箭射爆气球，points是气球的集合，可以看做vector<int>是一个气球的宽度
 * @details 首先按照气球的左边界进行排序，然后比较当前气球的左边界是否大于上一个气球的右边界，如果大于
 * 那么箭头的数量加一，否则更新当前气球的右边界，最后返回箭头数量
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if(points.size() <= 0) return 0;
        sort(points.begin(), points.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] < rhs[0];
        });

        int result = 1;
        for(int i = 1; i < points.size(); ++i) {
            if(points[i][0] > points[i-1][1])
                ++result;
            else {
                points[i][1] = min(points[i-1][1], points[i][1]);
            }
        }
        return result;
    }
};


#endif