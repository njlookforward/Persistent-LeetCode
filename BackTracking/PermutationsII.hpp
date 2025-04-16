#ifndef PERMUTATIONS_II_HPP
#define PERMUTATIONS_II_HPP

#include <vector>
using std::vector;

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


#endif