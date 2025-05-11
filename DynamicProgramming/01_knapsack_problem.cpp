#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
    public:
        int knapsack(int item_num, int capacity, const std::vector<int> &volumes, const std::vector<int> &values) {
            // 定义dp数组
            std::vector<std::vector<int>> dp(item_num, std::vector<int>(capacity + 1, 0));

            // 初始化dp数组
            for(int j = volumes[0]; j <= capacity; j++) {
                dp[0][j] = values[0];
            }

            // 使用递推公式
            for(int i = 1; i < item_num; i++) {
                for(int j = 1; j <= capacity; j++) {
                    if(j < volumes[i]) {
                        dp[i][j] = dp[i-1][j];
                    } else {
                        dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-volumes[i]] + values[i]);
                    }
                }
            }

            return dp[item_num - 1][capacity];
        }
};

int main() {
    int item_num;
    int capacity;
    std::cin >> item_num >> capacity;

    std::vector<int> volumes(item_num);
    std::vector<int> values(item_num);

    for(int i = 0; i < item_num; i++) {
        std::cin >> volumes[i];
    }

    for(int i = 0; i < item_num; i++) {
        std::cin >> values[i];
    }
    
    int maxValue = Solution().knapsack(item_num, capacity, volumes, values);
    std::cout << maxValue << std::endl;

    return 0;
}
    
    