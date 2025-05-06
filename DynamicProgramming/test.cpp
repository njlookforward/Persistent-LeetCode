#include "Unique_Paths_II.hpp"

void test_unique_paths_II()
{
    // vector<vector<int>> obstacleGrid(3, vector<int>(3,0));
    // obstacleGrid[1][1] = 1;
    vector<vector<int>> obstacleGrid(2, vector<int>(1,0));
    obstacleGrid[1][0] = 1;

    auto result = Solution().uniquePathsWithObstacles(obstacleGrid);
    cout << "result = " << result << endl;
}

int main()
{
    test_unique_paths_II();

    return 0;
}