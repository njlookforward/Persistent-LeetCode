#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 就是各种各样的循环，需要保证循环不变量，这样的思路才会清晰
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int loop = n / 2;   // 循环次数
        int startX = 0, startY = 0; // 循环开始的起点
        int offset = 1; // 循环不变量为左闭右开
        int count = 1;  // 起始数字
        int mid = n / 2;    // 中间位置

        while (loop--)
        {
            int i = startX,
                j = startY; // 必须在循环外进行定义，这样才能保证四个循环都可以连续使用
            
            // 从左到右
            for(j = startY; j < startY + n - offset; ++j)
                matrix[i][j] = count++;
            // 从上到下
            for(i = startX; i < startX + n - offset; ++i)
                matrix[i][j] = count++;
            // 从右到左
            for(; j > startY; --j)
                matrix[i][j] = count++;
            // 从下到上
            for(; i > startX; --i)
                matrix[i][j] = count++;

            // 开始下一次循环
            ++startX;
            ++startY;

            offset += 2;
        }

        if(n & 1)
            matrix[mid][mid] = count;
        
        return matrix;
    }
};