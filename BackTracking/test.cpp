// #include "Combination_Sum.hpp"
// #include "RestoreIPAddress.hpp"
#include "Non_decreasing_subsequences.hpp"
#include "exercise.hpp"
#include <iostream>
using std::cout; using std::endl;

// void test_combination_sum()
// {
//     vector<int> candidates{7,3,2};
//     int target = 18;
//     auto result = Solution().combinationSum(candidates, target);
//     for (auto &entry : result)
//     {
//         display(entry);
//     }
// }

// void test_restore_ip_address()
// {
//     // string s = "25525511135";
//     // string s = "0000";
//     string s = "101023";
//     auto result = Solution().restoreIpAddresses(s);
//     display(result);
// }

void test_non_decreasing_subsequences()
{
    vector<int> nums{1,2,3,4,5,6,7,8,9,10,1,1,1,1,1};
    auto result = Solution().findSubsequences(nums);
    for (auto &entry : result)
    {
        display(entry);
    }
}

int main()
{
    // test_combination_sum();
    // test_restore_ip_address();
    test_non_decreasing_subsequences();

    return 0;
}
