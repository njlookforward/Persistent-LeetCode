#ifndef COMBINATION_SUM_II_HPP
#define COMBINATION_SUM_II_HPP

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

// 人生第一次超时了，我的方法效率不行啊
class Solution {
public:
    // 这里不要忘记去重
    bool isDuplicate(const vector<vector<int>> &result, const vector<int> &path) {
        for (auto &entry : result)
        {
            if(entry.size() != path.size())
                continue;
            else {
                int i;
                for(i = 0; i < entry.size(); ++i) {
                    if(entry[i] != path[i])
                        break;
                }
                if(i == entry.size())
                    return true;
            }
        }
        return false;   
    }
    void backTracking(vector<int> &candidates, int target, int sum, int startIdx,
                      vector<int> &path, vector<vector<int>> &result) {
        if(sum == target) {
            if(!isDuplicate(result, path))
                result.push_back(path);
            return;
        }
        for(int i = startIdx; i < candidates.size() && sum + candidates[i] <= target; ++i) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backTracking(candidates, target, sum, i + 1, path, result);
            sum -= candidates[i];
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<int> path;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0, 0, path, result);
        return result;
    }
};

// 我的方法太笨了，应该使用卡哥的方法，注意是要##树层去重##，而是##树枝去重##
class Solution_carl {
public:
    void backTracking(vector<int> &candidates, int target, int sum, int startIdx,
                vector<bool> &used, vector<int> &path, vector<vector<int>> &result) {
        if(sum == target) {
            result.push_back(path);
            return;
        }
        for(int i = startIdx; i < candidates.size() && sum + candidates[i] <= target; ++i) {
            // 进行树层去重
            if(i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == 0)
                continue;   // 树层去重
            path.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backTracking(candidates, target, sum, i + 1, used, path, result);
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // 去重的前提是数组是有序的
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        vector<int> path;
        vector<vector<int>> result;
        backTracking(candidates, target, 0, 0, used, path, result);
        return result;
    }
};

#endif