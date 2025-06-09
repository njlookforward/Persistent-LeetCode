#ifndef MAXSUBARRAY_HPP
#define MAXSUBARRAY_HPP

#include <vector>
using std::vector;

#include <climits>
#include <algorithm>
using std::max;

/**
 * @brief 找到数组中最大连续子数组的和，采用分治法，也就是动态规划法，找到每一个
 * 以nums[i]为结尾的最大连续子序列和，然后找到其中的最大值就好
 * @details 
 * 1) d[i]：以nums[i]为结尾的最大连续子序列的和
 * 2） dp[i] = max(dp[i-1]+nums[i], nums[i]); 把nums[i]以前的序列看做一个整体，只有从这两个值中选一个最大值
 * 3) dp[i]的初始化问题：因为是从头到尾进行遍历，因此需要从dp[0]进行初始化，dp[0] = nums[0]
 * 4) dp数组的遍历就是从头到尾
 * @note time: O(n), space:O(n)
 * @bug 可能给定数组中只有一个数字
 */

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        if(nums.size() == 1) return dp[0];

        // bug: result的初始化是不对的
        int result = dp[0];
        for(int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);

            if(result < dp[i])
                result = dp[i];
        }



        return result;
    }
};



#endif