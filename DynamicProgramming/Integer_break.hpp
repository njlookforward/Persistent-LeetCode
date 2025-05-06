#ifndef INTEGER_BREAK_HPP
#define INTEGER_BREAK_HPP

// 不要放弃，不要逃避，敢于面对他，认认真真去想就好，战胜那个想要逃跑的自己，拿出20行，10分钟的勇气
// 我行的，我一定行的，我是天才
// 拿出你的勇气，拿出你的行动，拿出你的耐心，哪怕只有1分钟又如何

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

/**
 * @brief 将给定的整数n拆分成若干个相加可以得到n的整数，求这些拆分整数相乘可以得到的最大值
 * @details 基本思路就是将n拆分成m个近似相同的数
 * 1) dp[i]的含义：拆分i可以得到的最大乘积
 * 2) 递推公式：i可以拆分成2个，或者3个及以上，找到其中的最大值，因此dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]))
 * 3) dp[i]的初始化：dp[0] = 0; dp[1] = 0; dp[2]才开始有意义dp[2]=1
 * 4) 从前往后进行遍历
*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        // 因为已经初始化为0了，所以不需要重复赋值
        // dp[0] = 0;
        // dp[1] = 0;
        dp[2] = 1;
        // 对于for循环和if条件语句不要吝啬写curly brace，今天上午的教训已经够惨重了
        for(int i = 3; i <= n; i++) {
            // 这里存在一个小优化，j<=i/2;因为最大乘积一定在拆分成近似相同的值，因此中间值之后的值是没有意义的，肯定更小
            for(int j = 1; j <= i/2; j++) {
                dp[i] = max(dp[i], max(j * (i-j), j * dp[i-j]));
            }
        }
        return dp[n];
    }
};


#endif