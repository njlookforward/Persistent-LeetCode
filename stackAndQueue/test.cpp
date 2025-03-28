// #include "Sliding_Window_Maximum.hpp"
#include "topKFrequentElements.hpp"
#include <iostream>
using std::cout; using std::endl;

// void test_slidingwindow()
// {
//     // vector<int> nums{1,3,-1,-3,5,3,6,7};
//     vector<int> nums{1,3,1,2,0,5};
//     int k = 3;
//     auto res = Solution().maxSlidingWindow(nums, k);
//     for (auto &i : res)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
// }

void test_topkFrequent()
{
    // vector<int> nums{1,1,1,2,2,3};
    vector<int> nums{1};
    int k = 1;
    auto res = Solution().topKFrequent(nums, k);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    // test_slidingwindow();
    test_topkFrequent();

    return 0;
}