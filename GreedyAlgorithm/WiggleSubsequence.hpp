#ifndef WIGGLE_SUBSEQUENCE_HPP
#define WIGGLE_SUBSEQUENCE_HPP

#include <vector>
using std::vector;

#include <cstddef>
using std::size_t;

/**
 * @details
 * prediff = nums[i] - nums[i-1]; curdiff = nums[i+1]-nums[i]
 * key1: 通过画图，中间序列（不包含首尾元素），只取发生摆动的极值点，判断条件是(prediff < 0 && curdiff > 0) || (prediff > 0 && curdiff < 0)
 * key2: 上下有平坡的情况，只取平坡中的最后的一个点，因此判断条件改为(prediff <= 0 && curdiff > 0) || (prediff >= 0 && curdiff < 0)
 * key3: 首尾元素考虑：
 * key4: 单调坡中有平坡 
*/

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if(nums.size() == 1) return 1;
        int length = 1;
        int prediff = 0, curdiff;
        for(size_t i = 0; i < nums.size() - 1; ++i) {
            curdiff = nums[i + 1] - nums[i];
            if((prediff >= 0 && curdiff < 0) ||
               (prediff <= 0 && curdiff > 0)) {
                ++length;
                prediff = curdiff;
            }
        }
        return length;
    }
};

#endif