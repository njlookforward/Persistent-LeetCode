#include "Combination_Sum.hpp"
#include "exercise.hpp"
#include <iostream>
using std::cout; using std::endl;

void test_combination_sum()
{
    vector<int> candidates{7,3,2};
    int target = 18;
    auto result = Solution().combinationSum(candidates, target);
    for (auto &entry : result)
    {
        display(entry);
    }
}

int main()
{
    test_combination_sum();

    return 0;
}