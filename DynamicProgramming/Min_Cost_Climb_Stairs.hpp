#ifndef MIN_COST_CLIMB_STAIRS_HPP
#define MIN_COST_CLIMB_STAIRS_HPP

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

/**
 * @brief 最小花费爬楼梯，可以从index0或者index1开始爬楼梯，每次可以爬1个台阶或者2个台阶
 * @details
 * 1) dp[i]的含义是，i是从0开始的，达到第i个台阶所需要的最小花费
 * 2) 递推公式：站在第i个台阶上，不会花费cost[i]，只有向上爬的时候才会花费cost[i]，而且第i个台阶只有从第i-1阶
 * 或者i-2阶才能爬到，因此dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])
 * 3) dp[i]的初始化：dp[0] = 0; dp[1] = 0
 * 4) 遍历顺序就是从头到尾，后面的需要使用前面的结果
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= cost.size(); ++i) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[cost.size()];
    }
};


#endif