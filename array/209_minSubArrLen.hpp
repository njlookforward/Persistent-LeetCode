// #include <vector>
// using namespace std;

// // 使用滑动窗口法，i是窗口的起始位置，j是窗口的终止位置，i控制窗口的缩小，j控制窗口的扩大
// // i和j的任务是独立的，分开的，他们唯一的纽带就是sum总和，这样问题就好思考了
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int> &nums) {
//         int result = __INT32_MAX__;
//         int sum = 0;
//         int i = 0;
//         int subLength = 0;
//         for(int j = 0; j < nums.size(); ++j)
//         {
//             sum += nums[j];
//             while (sum >= target)
//             {
//                 subLength = j - i + 1;
//                 result = result < subLength ? result : subLength;
//                 sum -= nums[i++];   // 这是滑动窗口的精髓
//             }
//         }

//         return result == __INT32_MAX__ ? 0 : result;
//     }
// };
// // 时间复杂度为o(n)，最多两次遍历数列

#ifndef MINSUBARRAYLEN_HPP
#define MINSUBARRAYLEN_HPP

#include <vector>
using std::vector;

#include <climits>
#include <cstdint>

/**
 * @brief 找到数组中最小连续子序列的和要大于等于目标值
 * @details 可以使用暴力算法，但是应该使用滑动窗口，保证是O(n)的时间复杂度
 * @note time:O(n) space:O(1)
 * @bug 1) 忘记了递增endIndex，导致不停地访问第一个元素，没有正确的循环，现在编程太烂了
 * 2) 如果没有找到满足要求的子数组，那么result应该没有发生任何变化，应该返回0，但是自己忘记了，实在是不应该啊，还是欠练
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int result = INT32_MAX;
        int sum = 0;
        int curLength = 0;
        int begIndex = 0;
        for(int endIndex = 0; endIndex < nums.size(); endIndex++)
        {
            sum += nums[endIndex];

            // 这里是滑动窗口的主要精华，在for循环中移动的是endIndex, 在while循环中
            // 是移动滑动窗口的起始位置，通过一个while循环找到每一个有效滑动窗口的长度
            while (sum >= target)
            {
                curLength = endIndex - begIndex + 1;
                result = result < curLength ? result : curLength;
                sum -= nums[begIndex++];
            }
        }
        
        return result == INT32_MAX ? 0 : result;
    }
};



#endif