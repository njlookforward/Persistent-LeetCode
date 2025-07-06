// #include "42_接雨水.hpp"
// #include "1_两数之和.hpp"
#include "121_买卖股票的最佳时机.hpp"
#include <iostream>
using std::cout; using std::endl;

// void testTrap() {
//     // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
//     vector<int> height = {4, 2, 0, 3, 2, 5};

//     int res = Solution_double_pointer().trap(height);

//     cout << "res = " << res << endl;
// }

// void testTwoSum() {
//     // vector<int> nums{2, 7, 11, 15};
//     // int target = 9;

//     vector<int> nums{3,3};
//     int target = 6;
    
//     auto res = Solution_hash().twosum(nums, target);

//     cout << "[" << nums[res[0]] << ", " << nums[res[1]] << "]" << endl;
// }

void testMaxProfit() {
    vector<int> prices{7,1,5,3,6,4};
    // vector<int> prices{7,6,4,3,1};
    int maxProfit = Solution_v2().maxProfit(prices);
    cout << "maxProfit = " << maxProfit << endl;
}

int main(void) {
    // testTrap();
    // testTwoSum();
    testMaxProfit();

    return 0;
}