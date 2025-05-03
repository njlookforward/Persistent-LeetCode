// #include "Jump_Game_II.hpp"
// #include "GasStation.hpp"
#include "Non_overlapping_intervals.hpp"
#include <iostream>
using std::cout; using std::endl;

// void test_jump_game()
// {
//     vector<int> nums{3,2,1,0,4};
//     auto result = Solution_backTracking().canJump(nums);
//     cout << result << endl;
// }

// void test_jump_game_II()
// {
//     vector<int> nums = {5,8,1,8,9,8,7,1,7,5,
//     8,6,5,4,7,3,9,9,0,6,6,3,4,8,0,5,8,9,5,3,7,
//     2,1,8,2,3,8,9,4,7,6,2,5,2,8,2,7,9,3,7,6,9,
//     2,0,8,2,7,8,4,4,1,1,6,4,1,0,7,2,0,3,9,8,7,
//     7,0,6,9,9,7,3,6,3,4,8,6,4,3,3,2,7,8,5,8,6,0};
//     // vector<int> nums = {2,3,1,1,4};
//     // vector<int> nums = {2,3,0,1,4};
//     auto minJumpCnt = Solution().jump(nums);
//     cout << minJumpCnt << endl;
// }

// void test_gas_station()
// {
//     // vector<int> gas = {1,2,3,4,5};
//     // vector<int> cost = {3,4,5,1,2};
//     vector<int> gas = {2,3,4};
//     vector<int> cost = {3,4,3};
//     auto startIdx = Solution_violent().canCompleteCircuit(gas, cost);
//     cout << "从Index " << startIdx << " 开始" << endl;
// }

void test_non_overlapping_intervals()
{
    vector<vector<int>> intervals{
        {-52,31},{-73,-26},{82,97},{-65,-11},
        {-62,-49},{95,99},{58,95},{-31,49},
        {66,98},{-63,2},{30,47},{-40,-26}};
    int result = Solution().eraseOverlapIntervals(intervals);
    cout << "result is " << result << endl;
}

int main(void)
{
    // test_jump_game();
    // test_jump_game_II();
    // test_gas_station();
    test_non_overlapping_intervals();

    return 0;
}