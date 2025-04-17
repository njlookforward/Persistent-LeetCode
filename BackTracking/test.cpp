// #include "Combination_Sum.hpp"
// #include "RestoreIPAddress.hpp"
// #include "Non_decreasing_subsequences.hpp"
// #include "Reconstruct_Itinerary.hpp"
#include "N_Queens.hpp"
#include "exercise.hpp"
#include <iostream>
using std::cout; using std::endl; using std::cin;

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

// void test_non_decreasing_subsequences()
// {
//     vector<int> nums{1,2,3,4,5,6,7,8,9,10,1,1,1,1,1};
//     auto result = Solution().findSubsequences(nums);
//     for (auto &entry : result)
//     {
//         display(entry);
//     }
// }

// void test_reconstruct_itinerary()
// {
//     // vector<vector<string>> tickets = {
//     //     {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}
//     // };
//     vector<vector<string>> tickets = {
//         {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}
//     };
//     auto result = Solution_carl().findItinerary(tickets);
//     display(result);
// }

void test_n_queens()
{
    int n;
    while (1)
    {
        cout << "Please input a number which range from 1 to 9 to calculate n-queens puzzle or 0 to quit: ";
        cin >> n;
        if(n == 0)  break;
        auto result = Solution().solveNQueens(n);
        for (auto &chessboard : result)
        {
            display(chessboard);
            cout << endl;
        }
        cout << n << " queens has " << result.size() << " solutions." << endl;
    }
}

int main()
{
    // test_combination_sum();
    // test_restore_ip_address();
    // test_non_decreasing_subsequences();
    // test_reconstruct_itinerary();
    test_n_queens();

    return 0;
}
