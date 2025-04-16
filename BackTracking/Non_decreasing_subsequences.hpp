#ifndef NON_DECREASING_SUBSEQUENCES_HPP
#define NON_DERCEASING_SUBSEQUENCES_HPP

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

/// @brief 找到给定数组中的所有非递减子序列，仍然是寻找子集组合的问题
/// @details 目标子集必须是非递减的，而且必须包括2个及以上的元素
/// @bug 对于nums[4,6,7,7]没有考虑到重复子集的问题，不能偷懒，该使用used就得使用used
/// @bug 对于nums[1,2,3,4,5,6,7,8,9,10,1,1,1,1,1]出现问题，没有[1,1,1]这样的序列
/**
 * @bug 仍然是对于nums[1,2,3,4,5,6,7,8,9,10,1,1,1,1,1]出现问题，使用used树层去重无法处理同一树层中非连续重复元素
 * 题目要求的是子序列，因此无法先排序再使用used，因此需要使用unorder_set<int>记录同一树层中已经遍历过的元素
*/ 

class Solution
{
public:
    void backTracking(const vector<int> &nums, int startIdx,
            vector<int> &path, vector<vector<int>> &result)
    {
        if(path.size() >= 2)
            result.push_back(path);
        if(startIdx == nums.size()) return;
        unordered_set<int> used;    
        for(int i = startIdx; i < nums.size(); ++i) {
            // 这是我自己的逻辑出现问题，应该是当前
            if(!path.empty() && (nums[i] < path.back())) continue;
            if(used.count(nums[i])) continue;   // 当前层级去重
            used.insert(nums[i]);
            path.push_back(nums[i]);
            backTracking(nums, i + 1, path, result);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<int> path;
        vector<bool> used(nums.size(), false);
        vector<vector<int>> result;
        backTracking(nums, 0, path, result);
        return result;
    }
};

#endif