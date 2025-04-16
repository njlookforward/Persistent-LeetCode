#ifndef SUBSETS_II_HPP
#define SUBSETS_II_HPP

#include <vector>
using std::vector;

#include <algorithm>
using std::find; using std::sort;

// 我这种方法得到的是是所有的排列子集的集合，有顺序，但是leetcode题目的意思应该是组合的集合，就是不要求顺序，那就更简单了
class Solution_arrangement {
public:
    bool isExistSame(const vector<int> &nums, int startIdx, int i, vector<bool> &used) {
        auto bgit = nums.cbegin() + startIdx,
             edit = nums.cbegin() + i;
        auto findit = find(bgit, edit, nums[i]);
        if(findit != edit && used[findit - nums.cbegin()] == false)
            return true;
        else 
            return false;
    }
    void backTracking(const vector<int> &nums, int startIdx, vector<bool> &used,
                    vector<int> &path, vector<vector<int>> &result) {
        result.push_back(path);
        if(startIdx == nums.size()) return;
        for(int i = startIdx; i < nums.size(); ++i) {
            // 树层去重，需要在for循环的区间中进行遍历，for区间才是真正要去重的区间
            if(isExistSame(nums, startIdx, i, used)) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backTracking(nums, i + 1, used, path, result);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<int> path;
        vector<bool> used(nums.size(), false);
        vector<vector<int>> result;
        backTracking(nums, 0, used, path, result);
        return result;
    }
};

// BUG: 对于nums[4,4,4,1,4]，只比较同一层中的相邻数字是不够的，因为给定的数组是无序的，不能保证相同数字挨在一起
// 因此需要在数组中进行遍历寻找，只要前面有相同的数字，就要跳过

class Solution_combination {
public:
    void backTracking(const vector<int> &nums, int startIdx, vector<bool> &used,
                    vector<int> &path, vector<vector<int>> &result) {
        result.push_back(path);
        if(startIdx == nums.size()) return;
        for(int i = startIdx; i < nums.size(); ++i) {
            // 树层去重
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backTracking(nums, i + 1, used, path, result);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<int> path;
        vector<bool> used(nums.size(), false);
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        backTracking(nums, 0, used, path, result);
        return result;
    }  
};

#endif