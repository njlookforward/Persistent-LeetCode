#ifndef PERMUTATIONS_II_HPP
#define PERMUTATIONS_II_HPP

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

/**
 * @brief 因为给定数组中存在重复值，因此需要去重，仍然是同一层级进行去重，只要在同一层级中，这个数被遍历过了
 * 就跳过这一整个分支的遍历，仍然采用数组作为哈希表，因为数值范围确定且较小
*/

class Solution {
public:
    void backTracking(const vector<int> &nums, vector<bool> &used,
            vector<int> &path, vector<vector<int>> &result) {
        if(path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        bool levelUsed[21] = {0};
        for(int i = 0; i < nums.size(); ++i) {
//// @brief levelUsed[21]是哈希表，nums[i]是key, nums[i]+10是哈希函数，true/false就是value 
            if(used[i] || levelUsed[nums[i] + 10]) continue;
            levelUsed[nums[i] + 10] = true;
            used[i] = true;
            path.push_back(nums[i]);
            backTracking(nums, used, path, result);
            path.pop_back();
            used[i] = false;    
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<int> path;
        vector<bool> used(nums.size(), false);
        vector<vector<int>> result;
        backTracking(nums, used, path, result);
        return result;
    }
};

// 仍然可以使用sort + used数组进行树层去重，尽管此时used数组在全排列中的主要作用是标记该处数字是否被使用
// 但是因为已经经过排序了，而且是在发生重复的最高树层就进行去重，因此并不影响可以同时利用used进行树层去重
class Solution_carl {
public:
    void backTracking(const vector<int> &nums, vector<bool> &used,
                vector<int> &path, vector<vector<int>> &result) {
        if(path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            // 首先进行去重
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false) continue;
            if(used[i] == true) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backTracking(nums, used, path, result);
            used[i] = false;    
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<int> path;
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backTracking(nums, used, path, result);
        return result;
    }
};

#endif