/**
 * @brief 01 Knapsack Problem using a scrolling array
*/

// 永远都不要放弃，哪怕抄一遍又怎样？我就是要先完成，就完事了

// #include <iostream>
// using std::cin; using std::cout; using std::endl;

// #include <vector>
// using std::vector;

// #include <algorithm>
// using std::max;

// class Solution {
// public:
//     int knapsack(int m, int n, const vector<int> &volumes, const vector<int> &values) {
//         // dp[j]的含义：当背包容量为j的时候，能够存储的物品的最大价值
//         vector<int> dp(n+1, 0);
//         // 遍历顺序：先遍历物品，再后序遍历背包
//         for(int i = 0; i < m; i++) {
//             for(int j = n; j >= volumes[i]; j--) {
//                 dp[j] = max(dp[j], dp[j-volumes[i]] + values[i]);
//             }
//         }

//         return dp[n];
//     }
// };

// void test() {
//     // AI仍然是不准确的，需要多次进行提示，如下面的case1 and case2就是不对的
//     // Test Case 1
//     int item_nums1 = 3;
//     int capacity1 = 5;
//     vector<int> volumes1 = {2, 3, 4};
//     vector<int> values1 = {1, 2, 5};
//     int expected1 = 7;
//     int result1 = Solution().knapsack(item_nums1, capacity1, volumes1, values1);
//     cout << "Test Case 1: " << (result1 == expected1 ? "Passed" : "Failed") << endl;

//     // Test Case 2
//     int item_nums2 = 4;
//     int capacity2 = 10;
//     vector<int> volumes2 = {1, 3, 4, 5};
//     vector<int> values2 = {1, 4, 5, 7};
//     int expected2 = 9;
//     int result2 = Solution().knapsack(item_nums2, capacity2, volumes2, values2);
//     cout << "Test Case 2: " << (result2 == expected2 ? "Passed" : "Failed") << endl;

//     // Test Case 3
//     int item_nums3 = 2;
//     int capacity3 = 7;
//     vector<int> volumes3 = {3, 4};
//     vector<int> values3 = {2, 3};
//     int expected3 = 5;
//     int result3 = Solution().knapsack(item_nums3, capacity3, volumes3, values3);
//     cout << "Test Case 3: " << (result3 == expected3 ? "Passed" : "Failed") << endl;

//     // Test Case 4
//     int item_nums4 = 5;
//     int capacity4 = 12;
//     vector<int> volumes4 = {2, 3, 4, 5, 6};
//     vector<int> values4 = {1, 2, 3, 4, 5};
//     int expected4 = 9;
//     int result4 = Solution().knapsack(item_nums4, capacity4, volumes4, values4);
//     cout << "Test Case 4: " << (result4 == expected4 ? "Passed" : "Failed") << endl;
// }

// int main() {
//     // int item_nums;
//     // int capacity;
//     // cin >> item_nums >> capacity;

//     // vector<int> volumes(item_nums);
//     // for (auto &i : volumes)
//     // {
//     //     cin >> i;
//     // }
    
//     // vector<int> values(item_nums);
//     // for (auto &i : values)
//     // {
//     //     cin >> i;
//     // }

//     // cout << Solution().knapsack(item_nums, capacity, volumes, values);
//     test();

//     return 0;
// }

// 滚动数组需要满足的条件：二维数组中的上一层可以重复利用，直接拷贝到当前层，因此可以进行压缩
// 在滚动数组中，遍历的顺序不能颠倒；否则的话当前背包只会保存一个物品
#include <iostream>
using std::cout; using std::endl; using std::cin;
#include <vector>
using std::vector;
#include <algorithm>
using std::max;

class Solution {
public:
    int knapsack(int M, int bagCapacity, const vector<int> &weight, const vector<int> &value) {
        vector<int> dp(bagCapacity + 1, 0);
        for(int i = 0; i < M; ++i)
            for(int j = bagCapacity; j >= weight[i]; j--) {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        // for(int j = bagCapacity; j > 0; j--)
        //     for(int i = 0; i < M; ++i) {
        //         // 先遍历容量，在遍历物品，每个容量最后只会装入一件物品，因此是不可以的
        //         dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        //     }
        
            return dp[bagCapacity];
    }
};

int main(void) {
    // std::cout << "double = " << sizeof(double) << std::endl;
    int M, bagCapacity;
    cin >> M >> bagCapacity;

    vector<int> weight(M);
    for(int i = 0; i < M; ++i) 
        cin >> weight[i];
    
    vector<int> value(M);
    for(int i = 0; i < M; ++i)
        cin >> value[i];
    
    cout << "The most value of knapsack is " 
         << Solution().knapsack(M, bagCapacity, weight, value)
         << endl;

    return 0;
}