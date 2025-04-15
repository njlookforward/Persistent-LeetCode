#ifndef SUBSETS_HPP
#define SUBSETS_HPP

#include <vector>
using std::vector;

// 子集的关键：在每一层递归中收获结果，每一个节点都要收获结果
class Solution {
public:
    void backTracking(vector<int> &nums, int startIdx, vector<int> &path, vector<vector<int>> &result) {
        // 在每一层递归的时候收获结果
        result.push_back(path);
        if(startIdx == nums.size()) return; // 其实可以不写
        for(int i = startIdx; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            // BUg: 逻辑发生错误，写的时候不认真
            backTracking(nums, i + 1, path, result);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> path;
        vector<vector<int>> result;
        backTracking(nums, 0, path, result);
        return result;
    }
};

#endif