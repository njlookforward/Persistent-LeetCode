#ifndef SORTEDSQUARES_HPP
#define SORTEDSQUARES_HPP

#include <vector>
using std::vector;

/**
 * @brief 将一个非递减数组平方后，再进行排序
 * @details 需要使用双指针法，因为是平方，因此最大值只可能在两边，不可能在中间
 * @note    time: O(n); space: O(n);
 */

class Solution {
    vector<int> sortedSquares(vector<int> &nums) {
        vector<int> result(nums.size(), 0);
        for(int i = 0, j = nums.size() - 1, k = j; i <= j; ) {
            if(nums[i] * nums[i] > nums[j] * nums[j]) {
                result[k--] = nums[i] * nums[i];
                i++;
            } else {
                result[k--] = nums[j] * nums[j];
                j--;
            }
        }

        return result;
    }
};


#endif