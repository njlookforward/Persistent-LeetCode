#ifndef CLIMBING_STAIRS_HPP
#define CLIMBING_STAIRS_HPP

#include <vector>
using std::vector;

/**
 * @brief 爬楼梯问题相当于斐波那契数列
 * @details 
 * 1) dp[i]就是达到i阶楼梯数有dp[i]种方法
 * 2) 递推公式：dp[i] = dp[i-1] + dp[i-2]，为什么是这种方法，因为每一次可以爬1阶或者2阶楼梯，因此爬i阶楼梯
 * 可以由爬i-2阶楼梯再爬两阶达到，或者爬i-1阶楼梯再爬一节楼梯达到
 * 3) dp数组的初始化问题 dp[1] = 1; dp[2] = 2
 * 4) 遍历顺序，肯定是从前往后
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<int> dp(n+1);
        // dp[0] = 1;   因为dp[0]没有意义，只是为了实现这个算法才这样做的
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


#endif