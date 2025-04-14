#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include <vector>
using std::vector;

// 组合问题只能用回溯解决。回溯问题就是用递归函数，每一层递归就是一次for循环，单层递归中的for循环决定
// 这颗n叉树的宽度，递归的层数决定了n叉树的高度，设计回溯也是有回溯三部曲
class Solution {
public:
    // 基本回溯中的n叉树都是先序遍历，从上往下进行，因此采用多引用形参的方式遍历
    void backTracking(int n, int k, int startIdx, vector<int> &path, vector<vector<int>> &result)
    {
        if(path.size() == k) {
            // 来到叶子结点进行收割
            result.push_back(path);
            return;
        }
        // 剪枝操作过程：path中还需要k - path.size()的个元素，因此i最大的索引是n - (k - path.size()) + 1
        for(int i = startIdx; i <= n - (k-path.size()) + 1; ++i) {
            path.push_back(i);
            backTracking(n, k, i + 1, path, result);
            path.pop_back();    // 回溯操作
        }
        return;
    }
    vector<vector<int>> combine(int n ,int k) 
    {
        vector<vector<int>> result;
        vector<int> path;
        backTracking(n, k, 1, path, result);
        return result;
    }
};


#endif  // COMBINATION_HPP