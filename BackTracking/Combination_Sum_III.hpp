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

#endif