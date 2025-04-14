#ifndef COMBINATION_SUM_HPP
#define COMBINATION_SUM_HPP

#include <vector>
using std::vector;

#include <numeric>
using std::accumulate;

#include <algorithm>
using std::sort;

// 我的方法没有问题，但是只击败%5.21，我服了！！！！
// 这个信号只能管一层，当相等或大于时，这一层就没有必要再继续进行for循环，直接返回上一层
enum class signal {less, equal, greater};

// 之前的combination_sum_III题目中规定了k个元素的总和，说明了递归的深度是固定的，就是k层
// 但是这道题目说候选数字可以重复使用，说明递归的层数是可变的，只能以结果为导向
class Solution {
public:
    // 通过这个函数确定是否不重复
    bool isDuplicate(const vector<vector<int>> &result, const vector<int> &path) {
        for (auto &entry : result)
        {
            if(entry.size() != path.size())
                continue;
            else {
                int i;
                for (i = 0; i < entry.size(); i++)
                {
                    if(entry[i] != path[i])
                        break;
                }
                if(i == entry.size())
                    return true;
            }
        }
        return false;
    }
    // 注意这里的candidates是有序且不重复的数字集合
    enum signal backTracking(vector<int> &candidates, int target, vector<int> &path, vector<vector<int>> &result)
    {
        int sum = accumulate(path.cbegin(), path.cend(), 0);
        if(sum == target) {
            // 这种写法写完之后，还需要进行去重
            // Bug: 不能直接对path排序，会打乱回溯的顺序，因此只能复制一份再排序
            // sort(path.begin(), path.end());
            auto copyPath(path);
            sort(copyPath.begin(), copyPath.end());
            if(!isDuplicate(result, copyPath))
                result.push_back(copyPath);
            return signal::equal;
        } else if(sum > target)
            return signal::greater;
        for(int i = 0; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            auto ret = backTracking(candidates, target, path, result);
            path.pop_back();
            if(ret != signal::less)
                return signal::less;
        }
        return signal::less;
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<int> path;
        vector<vector<int>> result;
        // BUG:题目中的candidates不一定是有序的，因此需要先排序
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, path, result);
        
        return result;
    }
};

class Solution_carl {
public:
    // 这里面的startIdx保证组合不会重复，很巧妙啊
    void backTracking(vector<int> &candidates, int target, int sum, int startIdx, 
                      vector<int> &path, vector<vector<int>> &result) {
        if(sum == target) {
            result.push_back(path);
            return;
        } // else if(sum > target)
        //    return;
        // key: 优化的剪枝操作
        for(int i = startIdx; i < candidates.size() && sum + candidates[i] <= target; ++i) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backTracking(candidates, target, sum, i, path, result);
            sum -= candidates[i];
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<int> path;
        vector<vector<int>> result;
        // BUG：剪枝操作的前提是数组必须有序，保证后面的组合一定比前面的组合大
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0, 0, path, result);
        return result;
    }
};

#endif