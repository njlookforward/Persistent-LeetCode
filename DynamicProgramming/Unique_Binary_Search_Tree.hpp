#ifndef UNIQUE_BINARY_SEARCH_TREE_HPP
#define UNIQUE_BINARY_SEARCH_TREE_HPP

/**
 * @njlookforward 南江，你行的，你就是行的，这道小问题难不倒你，给我攻克它
*/

#include <vector>
using std::vector;

/**
 * @brief 给定一个节点数量n，求n个节点一共可以组成多少种二叉搜索树
 * @details 仍然按照动规五部曲进行思考
 * 1) dp[i]含义：i个节点可以组成dp[i]种二叉搜索树
 * 2) 递推公式：从1到i分别作为头结点，以n为3为例
 * dp[3] = 头1 + 头2 + 头3 = dp[0]*dp[2] + dp[1]*dp[1] + dp[2]*dp[0]；
 * 因为这是二叉搜索树，因此左子树和右子树的数量可以通过头结点进行确定，因此可以得到递推公式
 * dp[i] += dp[j-1] * dp[i-j], j是从1到i进行遍历
 * 3) dp[i]的初始化问题：dp[0] = 1, 空节点就是一棵二叉搜索树，它什么树都是
 * 4) 因为需要前面dp数组中的状态才能推导出当前dp[i]的状态，因此是从前往后，从小到大进行遍历
 * @note 
 * 1) 时间复杂度O(n^2)
 * 2) 空间复杂度O(n)
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            } 
        }
        return dp[n];
    }
};


#endif