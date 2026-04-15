#include <iostream>
#include <string>
#include <vector>
#include <deque>

using std::cout, std::cin, std::endl;
using std::string;
using std::vector;
using std::deque;
using std::pair;

// 这考察的是广度优先遍历算法，需要使用队列，然后不停地出队与入队
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        // 需要先遍历二维数组，记录的已经腐烂的橘子的位置与新鲜橘子的数量
        int freshes = 0;
        deque<pair<int, int>> deq;
        for(size_t i = 0; i < grid.size(); i++)
        {
            for(size_t j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 2)
                {
                    deq.push_back({i,j});
                } else if(grid[i][j] == 1) 
                {
                    ++freshes;
                }
            }
        }

        // 通过BFS将逐层使新鲜的橘子腐烂，记录使用的时间
        // 对于这种二维数组的位置操作，应该使用一个辅助数组
        vector<pair<int, int>> movePosSet {
            // bug1: 坐标写错了，下次要小心，不要再放着种错误
            {0, -1}, {-1, 0}, {0, 1}, {1, 0}
        };  // 左 上 右 下
        int times = 0;
        while(!deq.empty() && freshes)
        {
            size_t levelNum = deq.size();
            // bug3：这里的++i竟然写错了，实在不应该
            for(size_t i = 0; i < levelNum; ++i)
            {
                auto pos = deq.front();
                deq.pop_front();
                for (auto & movePos : movePosSet)
                {
                    // 只需要分开行与列就好了，还可以分开进行判断是否合法
                    int row = pos.first + movePos.first;
                    int col = pos.second + movePos.second;
                    // 列出所有的非法情况
                    if(row < 0 || row >= grid.size() ||
                       col < 0 || col >= grid[0].size() ||
                       grid[row][col] != 1)
                    {
                        continue;
                    } else
                    {
                        // bug2: 这里缺少一个过程，没有更新为腐烂的橘子
                        grid[row][col] = 2;
                        --freshes;
                        deq.push_back({row, col});
                    }
                }
            }
            ++times;
        }
        if(freshes) {
            return -1;
        } else 
            return times;
    }
};

void test1() {
    vector<vector<int>> grid {
        {2,1,1}, {1,1,0}, {0,1,1}
    };

    auto res = Solution().orangesRotting(grid);

    cout << "res = " << res << endl;
}

int main(int argc, char *argv[]) {
    test1();

    return 0;
}