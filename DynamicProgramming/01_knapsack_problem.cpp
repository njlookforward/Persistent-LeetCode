// #include <vector>
// #include <iostream>
// #include <algorithm>

// class Solution {
//     public:
//         int knapsack(int item_num, int capacity, const std::vector<int> &volumes, const std::vector<int> &values) {
//             // 定义dp数组
//             std::vector<std::vector<int>> dp(item_num, std::vector<int>(capacity + 1, 0));

//             // 初始化dp数组
//             for(int j = volumes[0]; j <= capacity; j++) {
//                 dp[0][j] = values[0];
//             }

//             // 使用递推公式
//             for(int i = 1; i < item_num; i++) {
//                 for(int j = 1; j <= capacity; j++) {
//                     if(j < volumes[i]) {
//                         dp[i][j] = dp[i-1][j];
//                     } else {
//                         dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-volumes[i]] + values[i]);
//                     }
//                 }
//             }

//             return dp[item_num - 1][capacity];
//         }
// };

// int main() {
//     int item_num;
//     int capacity;
//     std::cin >> item_num >> capacity;

//     std::vector<int> volumes(item_num);
//     std::vector<int> values(item_num);

//     for(int i = 0; i < item_num; i++) {
//         std::cin >> volumes[i];
//     }

//     for(int i = 0; i < item_num; i++) {
//         std::cin >> values[i];
//     }
    
//     int maxValue = Solution().knapsack(item_num, capacity, volumes, values);
//     std::cout << maxValue << std::endl;

//     return 0;
// }
    
// 我需要再次刷一遍01背包二维数组的实现，这次采用ACM方式要有输入和输出
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_maxValue(vector<int> weight, vector<int> value, int M, int N) {
    // 定义dp数组
    vector<vector<int>> dp(M, vector<int>(N + 1, 0));
    // dp数组的初始化问题
    // @bug: 我竟然用的是j <= N+1，真是可恶啊
    for(int j = weight[0]; j <= N; ++j) {
        dp[0][j] = value[0];
    }
    // dp数组的遍历
    // 状态转移方程
    for(int i = 1; i < M; ++i)
        for(int j = 1; j <= N; ++j) {
            if(j < weight[i])
                dp[i][j] = dp[i-1][j];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
        }
    
    return dp[M-1][N];
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<int> weight(M, 0);
    for(int i = 0; i < M; ++i) 
        cin >> weight[i];
    
    vector<int> value(M, 0);
    for(int i = 0; i< M; ++i) {
        cin >> value[i];
    }
    
    cout << get_maxValue(weight, value, M, N);

    return 0;
}