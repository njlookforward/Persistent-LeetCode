#ifndef LAST_STONE_WEIGHT_II_HPP
#define LAST_STONE_WEIGHT_II_HPP

// question 1: 头文件保护符是不是不能以数字开头，只能是字母或者下划线开头
#include <vector>
using std::vector;

#include <algorithm>
using std::max;

#include <numeric>
using std::accumulate;

/**
 * @brief 一个数组中找到两块石头，两个石头两两相撞，要找到能剩下的最小重量
 * 和上一题的分割等和子集的道理是一样的，尽量将两堆石头分成重量相等的两份
 * 仍然可以总结成01背包问题，尽量分成石头总和重量的一半
 */

class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {
        int sum = accumulate(stones.cbegin(), stones.cend(), 0);
        int target = sum / 2;
        // dp数组，dp[j]，背包容量为i的背包能够从[0,i]中拿到最大的物品价值
        // 在这里物品的价值就是物品的重量
        vector<int> dp(target + 1, 0);
        for(int i = 0; i < stones.size(); i++) {
            for(int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
            }
        }

        // 因为/是向下取整，因此sum-dp[target]是更大的
        return sum - dp[target] - dp[target];
    }
};

#endif