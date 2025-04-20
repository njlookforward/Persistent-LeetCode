#ifndef JUMP_GAME_HPP
#define JUMP_GAME_HPP

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

class Solution_backTracking {
public:
    bool backTracking(vector<int> &nums, int index, int lastIdx) {
        if(index == lastIdx)    return true;
        else if(nums[index] == 0 && index < lastIdx) return false;
        else if(index > lastIdx) return false;
        int jumpCnt = nums[index];
        for(int i = 1; i <= jumpCnt; ++i) {
            index += i;
            if(backTracking(nums, index, lastIdx)) return true;
            index -= i;
        }
        return false;   
    }
    bool canJump(vector<int> &nums) {
        return backTracking(nums, 0, nums.size() - 1);
    }
};

class Solution_carl {
public:
    bool canJump(vector<int> &nums) {
        // 不纠结跳几步，只看覆盖范围
        int cover = 0;
        if(nums.size() == 1) return true;
        for(int i = 0; i <= cover; ++i) {
            cover = max(i + nums[i], cover);
            if(nums.size() - 1 <= cover)    return true;
        }
        return false;
    }
};

#endif