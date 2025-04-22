#ifndef JUMP_GAME_II_HPP
#define JUMP_GAME_II_HPP

#include <vector>
using std::vector;

#include <algorithm>
using std::min; using std::max;

#include <cstddef>
using std::size_t;

#include <climits>

class Solution_backTracking {
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

class Solution_greedy {
public:
    int jump(vector<int> &nums) {
        /**
         * @brief 求从数组起点到终点的最少跳跃次数
         * @details 思路是不要想具体怎么跳，而是每一步尽可能地扩大覆盖范围，用最少的次数达到最大范围
         * 因此要确定当前这一步的覆盖范围[i, cur]，和下一步的覆盖范围(cur, next]
        */

        /**
         * @param cur 当前这一步可以选择的最大落脚位置索引
         * @param next 表示最大覆盖范围，同时表示下一步可以选择的最大落脚位置索引
         * @param for循环中的i，表示当前的落脚位置索引，同时也承担表示当前这一步落脚位置的起始索引
        */

       /**
        * @attention 确定这些数据结构对象，可以看出编程的功力深浅，我最初的大体思路是正确的,
        * 但是使用left right i cover result太过冗余，而且for循环没有想清楚，太乱了，上面的设计刚刚好
       */
       if(nums.size() <= 1) return 0;
       int cur = 0, next = 0;
       int result = 0;
       for(int i = 0; i < nums.size(); ++i) {
            next = max(next, i + nums[i]);
            if(cur == i) {
                // 到达这一步的最大落脚位置索引
                if(cur < nums.size() - 1) {
                    ++result;
                    cur = next;
                }
                // 必须是跳完之后再判断此时cur能否到达nums.size()-1，而且是>=，这是个细节
                if(cur >= nums.size() - 1) break;
            }
       }
       return result;
    }
};

#endif