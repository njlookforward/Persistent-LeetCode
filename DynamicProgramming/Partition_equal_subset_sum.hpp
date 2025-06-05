#ifndef PARTITION_EQUAL_SUBSET_SUM_HPP
#define PARTITION_EQUAL_SUBSET_SUM_HPP

#include <vector>
using std::vector;

#include <numeric>
using std::accumulate;

#include <algorithm>
using std::max;

/**
 * @brief 分割等和子集，就是能够找到元素集合的总和等于给定集合总和的一半
 * 其中的元素，要么取，要么不取，我的背包的容量是集合的一半，能否装满这个背包
 */
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sumSet = accumulate(nums.cbegin(), nums.cend(), 0);
        // 需要相信自己的判断，应该需要先判断是否为奇数，
        // 如果是奇数的话肯定不可能分为两个相等的区间，因此直接返回false
        if(sumSet & 1) return false;
        int halfSum = sumSet / 2;

        // 不要忘记dp数组是从0到halfSum
        vector<int> dp(halfSum + 1, 0);
        for(int i = 0; i < nums.size(); ++i)
            for(int j = halfSum; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        
        if(dp[halfSum] == halfSum)
            return true;
        else 
            return false;
    }
};


#endif