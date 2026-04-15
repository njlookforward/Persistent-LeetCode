#ifndef __THREESUM_HPP__
#define __THREESUM_HPP__

#include <vector>
using std::vector;
#include <set>
using std::set;
#include <algorithm>
using std::sort;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // 不可以包含重复的三元组，因此使用set<vector<int>> 进行去重
        // 首先需要排序，这样可以使用双指针找到目标
        vector<vector<int>> res;
        set<vector<int>> res_set;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int aim = -nums[i];
            for(int j = i + 1, k = nums.size() - 1; j < k; ) {
                if(nums[j] + nums[k] == aim) {
                    vector<int> oneResult{nums[i], nums[j], nums[k]};
                    res_set.insert(oneResult);
                    j++;
                    k--;
                } else if(nums[j] + nums[k] < aim) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        res.insert(res.begin(), res_set.begin(), res_set.end());
        return res;
    }
};

#endif