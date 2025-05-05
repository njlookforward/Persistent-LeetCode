#ifndef FIBONACCI_NUMBER_HPP
#define FIBONACCI_NUMBER_HPP

#include <vector>
using std::vector;

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        else if(n == 1) return 1;
        else
            return fib(n-1) + fib(n-2);
    }
};

/**
 * @brief f(n) = f(n-1) + f(n-2)
 * @details 这道题虽然简单，但是可以梳理动态规划的5步方法论
 * 1) dp[i]数组，第i个数组元素表示第i个斐波那契数
 * 2) 递推公式 dp[i] = dp[i-1] + dp[i-2];
 * 3) dp数组如何进行初始化 dp[0] = 0; dp[1] = 1
 * 4) 遍历顺序 从前往后进行遍历，因为该层只与上两层有关系，因此可以进行状态压缩，dp数组只需要包含3个元素
 * 5) 打印dp数组，该步骤其实是用来debug的，找到代码实现细节中的错误 
*/

class Solution_dynamic {
public:
    int fib(int n) {
        // 首先进行边界检查
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};

#endif