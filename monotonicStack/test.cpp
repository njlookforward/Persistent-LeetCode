#include "trappingRains.hpp"
#include <iostream>
using std::cout; using std::endl;

void test_trapRain()
{
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    auto res = Solution_simplify().trap(height);
    cout << res << endl;
}

int main()
{
    test_trapRain();

    return 0;
}