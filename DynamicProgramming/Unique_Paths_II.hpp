#ifndef UNIQUE_PATHS_II_HPP
#define UNIQUE_PATHS_II_HPP

#include "common.hpp"
#include <vector>
using std::vector;

/**
 * @brief 仍然是在网格中的不同路径问题，但是存在障碍物，虽然添加了条件，但是分析过程仍然和unique paths是一样的
 * @details
 * 1) dp[i][j]含义：从[0,0]到[i,j]共有dp[i,j]中不同路径
 * 2) 递推公式：因为仍然是在每一个网格只能向右或者向下进行移动一个单位，因此dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * 但是存在obstacle，需要添加判断条件：obstacleGrid[i][j] ? 0 : (dp[i-1][j] + dp[i][j-1])
 * 3) dp[i][j]的初始化：仍然是初始化最上和最左，但是需要考虑到障碍物，只要在最上的某一位置有obstacle，该位置及以后都为0
 * 4) 仍然是从上往下，从左往右进行遍历
 * 5) 因为出现错误，我需要打印dp[i][j]，通过打日志找出问题
 * 
 * @attention 就因为各种马虎，发生很多错误，实在是不应该啊，要专心，不要分心
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size(),
            n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 寻找最左是否存在障碍物
        // 寻找最上是否存在障碍物
        // 进行初始化，障碍物及以后都初始化为0
        // 从上到下从左到右进行遍历，便利的同时使用递推公式，在有障碍物的条件下使用递推公式
        // 返回最后一个方格的不同路径
        int rowObstacle = m;
        for(int i = 0; i < m; i++) 
            if(obstacleGrid[i][0] == 1) {
                rowObstacle = i;
                break;
            }
        int colObstacle = n;
        for(int j = 0; j < n; j++)
            if(obstacleGrid[0][j] == 1) {
                colObstacle = j;
                break;
            }
        
        for(int i = 0; i < rowObstacle; i++)
            dp[i][0] = 1;
        // 因为初始化的时候就已经是0了，所以不需要再次赋值了
        // for(int i = rowObstacle; i < m; i++)
        //     dp[i][0] = 0;
        for(int j = 0; j < colObstacle; j++)
            dp[0][j] = 1;
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++) {
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0
                                                   : (dp[i-1][j] + dp[i][j-1]);
            }
        // display(dp);

        return dp[m-1][n-1];
    }
};

class Solution_carl {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        /**
         * @note 需要进行优化的两个点
         * 1) 判断特殊情况，如果障碍物在起始位置和终点位置，那么直接返回0，没法走
         * 2) dp[i][j]初始化思路更加简洁，在判断条件中添加obstacleGrid[i][0] == 0即可，不需要分开
        */
       int m = obstacleGrid.size();
       int n = obstacleGrid[0].size();
       if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

       vector<vector<int>> dp(m, vector<int>(n,0));
       for(int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
            dp[i][0] = 1;
       }
       for(int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {
            dp[0][j] = 1;
       }
       for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            // 因为已经初始化为0了，就没有必要进行二次赋值
            if(obstacleGrid[i][j] == 1) continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]);
        }
       }
       return dp[m-1][n-1];
    }
};

#endif