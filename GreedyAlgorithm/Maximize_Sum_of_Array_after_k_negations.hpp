#ifndef MAXIMIZE_SUM_OF_ARRAY_AFTER_K_NEGATIONS_HPP
#define MAXIMIZE_SUM_OF_ARRAY_AFTER_K_NEGATIONS_HPP

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

#include <numeric>
using std::accumulate;

#include <cmath>
using std::abs;

/**
 * @details 思路是首先从小到大进行排序，从最小的开始改变，如果都是正数，永远都在第一个数进行改变
 * 如果开始是负数，那么取反后，在下一轮取反时需要和下一个数进行比较，如果比下一个数大，那么最小的数移到下一位
 * 已经移到最后一位了，说明都取反了，此时需要进行重新排序，来到第一位是最小值
 * @bug 对于[-4, -2, -3], k = 4来说出现问题，必须确保Idx在有效的范围内
 * @njlookforward 我自己做出来了
*/

class Solution {
public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int idx = 0;
        while (k--)
        {
            if(idx >= nums.size() - 1) {
                sort(nums.begin(), nums.end());
                idx = 0;
            }
            if(nums[idx] > nums[idx+1])
                ++idx;
            nums[idx] = -nums[idx];
        }
        
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

/**
 * @details 卡哥的算法更加巧妙，将数组按照绝对值大小从大到小进行排列，只要遇到负数就取反
 * 如果遍历数组结束后，k仍然非零，那么对数组最后一个数反复取反
*/

class Solution_greedy {
public:
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                --k;
            }
        }

        if(k % 2 == 1) nums[nums.size()-1] *= -1;
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

#endif