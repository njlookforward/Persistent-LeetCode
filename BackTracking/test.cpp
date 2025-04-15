// #include "Combination_Sum.hpp"
#include "RestoreIPAddress.hpp"
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

void test_restore_ip_address()
{
    // string s = "25525511135";
    // string s = "0000";
    string s = "101023";
    auto result = Solution().restoreIpAddresses(s);
    display(result);
}

int main()
{
    // test_combination_sum();
    test_restore_ip_address();

    return 0;
}