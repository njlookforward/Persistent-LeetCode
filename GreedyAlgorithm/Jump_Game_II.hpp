#ifndef JUMP_GAME_II_HPP
#define JUMP_GAME_II_HPP

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

#include <cstddef>
using std::size_t;

#include <climits>

class Solution {
public:
    void backTracking(vector<int> &nums, int index, int lastIdx, int jumpCnt, int &result) {
        if(jumpCnt >= result) return;
        if(index == lastIdx) {
            result = min(jumpCnt, result);
            return;
        }
        if(index > lastIdx) return;
        else if(nums[index] == 0 && index < lastIdx) return;
        for(size_t i = nums[index]; i >= 1; --i) {
            index += i;
            ++jumpCnt;
            backTracking(nums, index, lastIdx, jumpCnt, result);
            --jumpCnt;
            index -= i;
        }
    }
    int jump(vector<int> &nums) {
        int result = INT_MAX;
        backTracking(nums, 0, nums.size()-1, 0, result);
        return result;
    }
};

#endif