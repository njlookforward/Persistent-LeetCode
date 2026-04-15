/**
 * @brief 编辑距离
 * 数组应该如何表示 + 数组初始化 + 状态转移方程
 */
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    template <typename Sequence>
    int minDistance(const Sequence &src, const Sequence &dst) const {
        // 1. 创建数组
        size_t m = dst.size();
        size_t n = src.size();
        vector<vector<int>> dp(m + 1, vector<int>(n+1, 0));

        // 2. 初始化
        for(int i = 1; i <= m; ++i) {
            dp[i][0] = i;
        }
        for(int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }

        // 3. 状态转移方程
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                int insert = dp[i-1][j] + 1;
                int remove = dp[i][j-1] + 1;
                int modify = dp[i-1][j-1] + (src[j-1] != dst[i-1]);
                dp[i][j] = min({insert, remove, modify});   // BUG 这应该是一个列表的形式，不要忘记{}
            }
        }

        return dp[m][n];
    }
};

int main() {
    // string src("horse");
    // string dst("ros");

    string src("nanjiang");
    string dst("qushuai");

    int distance = Solution{}.minDistance(src, dst);

    cout << "distance = " << distance << endl;

    return 0;
}