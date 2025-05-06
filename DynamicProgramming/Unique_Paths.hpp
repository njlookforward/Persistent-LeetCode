#ifndef UNIQUE_PATHS_HPP
#define UNIQUE_PATHS_HPP

#include <vector>
using std::vector;

/**
 * @brief 在网格上只能向右或者向下移动一个单位，从[0,0]到[m-1, n-1]有多少种不同路径，需要使用动态规划的方法
 * @details 动规五部曲
 * 1) dp[i][j]的含义：从[0,0]到[i,j]的一共有dp[i,j]种不同路径
 * 2) 递推公式：因为只能向右或者向下走，因此[i,j]只能从[i-1,j]或[i,j-1]处来到，因此dp[i,j] = dp[i-1,j] + dp[i,j-1];
 * 3) dp[i,j]的初始化问题，因为任何一个位置都是由上和左得到的，因此最上和最左必须进行初始化
 * 4) 有递推公式可知每一个位置由上和左决定，因此应该从上往下，从左往右进行遍历
 * @attention dp[0,0] = 1,必须是1，因为测试用例是1
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 1) 定义dp数组
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 2) 初始化dp数组
        for(int i = 0; i < m; i++) 
            dp[i][0] = 1;
        for(int j = 0; j < n; j++)
            dp[0][j] = 1;
        
        // 3) 确定遍历顺序
        // 4) 在遍历中确定递推公式
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        return dp[m-1][n-1];
    }
};


#endif