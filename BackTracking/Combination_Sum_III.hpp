#ifndef COMBINATION_SUM_III_HPP
#define COMBINATION_SUM_III_HPP

#include <vector>
using std::vector;

#include <numeric>
using std::accumulate;

enum class signal {less, equal, greater};

class Solution {
public:
    // 通过返回值判断应不应该继续遍历
    // Bug1: 返回值应该是enum signal，不要忘记enum
    enum signal backTracking(int k, int n, int startIdx, vector<int> &path, vector<vector<int>> &result)
    {
        // if(path.size() == k) {
        //     int sum = accumulate(path.cbegin(), path.cend(), 0);
        //     if(sum == n) {
        //         result.push_back(path);
        //         return signal::equal;
        //     } else if(sum > n)
        //         return signal::greater;
        //     else
        //         return signal::less;
        // }
        // 我如果反着想，先考虑结果再考虑path中的个数
        int sum = accumulate(path.cbegin(), path.cend(), 0);
        if(sum > n)
            return signal::greater;
        else if(sum == n) {
            if(path.size() == k)
            {
                result.push_back(path);
            }
            return signal::equal;
        } else if(sum < n && path.size() == k)  // Bug3:少讨论一种情况
            return signal::less;
        for(int i = startIdx; i <= 9; ++i) {
            path.push_back(i);
            enum signal ret = backTracking(k, n, i + 1, path, result);
            path.pop_back();
            if(ret == signal::equal)
                return signal::less;
            else if(ret == signal::greater)
                return signal::less;
        }
        // Bug2:忘记写返回值
        return signal::less;    // 其实无关紧要
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        backTracking(k, n, 1, path, result);
        return result;
    }
};

class Solution_carl {
public:
    void backTracking(int k, int n, int sum, int startIdx, vector<int> &path,
                      vector<vector<int>> &result) {
        if(sum == n && path.size() == k) {
            result.push_back(path);
            return;
        }
        // BUG：没有理解题意，题目限制在1-9之间取数
        // key：对于明确要求k个数字的组合，剪枝操作就是n-(k-path.size())+1;如果还有sum值的话
        // && sum + candidates[i] <= target;
        for(int i = startIdx; i <= 9 - (k-path.size()) + 1 && sum + i <= n; ++i) {
            path.push_back(i);
            sum += i;
            backTracking(k, n, sum, i + 1, path, result);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int>> result;
        backTracking(k, n, 0, 1, path, result);
        return result;
    }
};

#endif