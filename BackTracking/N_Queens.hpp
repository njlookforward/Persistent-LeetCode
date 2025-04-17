#ifndef N_QUEENS_HPP
#define N_QUEENS_HPP

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
public:
    void backTracking(vector<vector<string>> &result, vector<string> &chessboard, int row, int n);
    bool isValid(const vector<string> &chessboard, int row, int col, int n);
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> chessboard(n, string(n, '.'));
        backTracking(result, chessboard, 0, n);
        return result;
    }
};

void Solution::backTracking(vector<vector<string>> &result, 
                vector<string> &chessboard, int row, int n) {
    if(row == n) {
        result.push_back(chessboard);
        return;
    }
    for(int col = 0; col < n; ++col) {
        if(isValid(chessboard, row, col, n)) {
            chessboard[row][col] = 'Q';
            backTracking(result, chessboard, row + 1, n);
            chessboard[row][col] = '.';
        }
    }
}

// 按照carl的算法，检验操作需要进行剪枝操作，因为我们是从上往下一次确定每行皇后的位置，
// 因此只需要检验[row, col]以上范围就可以
bool Solution::isValid(const vector<string> &chessboard, int row, int col, int n) {
    // 检查列
    for(int i = row - 1; i >= 0; --i) {
        if(chessboard[i][col] == 'Q')
            return false;
    }
    // 不需要检查行，因为backTracking()递归中的单层逻辑只会让每一层中的一个元素为皇后，事实上这一行此时都是'.'
    // 检查45°
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i,--j) {
        if(chessboard[i][j] == 'Q')
            return false;   
    }
    // 检查135°
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
        if(chessboard[i][j] == 'Q')
            return false;   
    }
    return true;
}

// 我自己的实现
// bool Solution::isValid(const vector<string> &chessboard, int row, int col, int n) {
//     // up
//     for(int i = row - 1; i >= 0; --i) {
//         if(chessboard[i][col] == 'Q')
//             return false;
//     }
//     // right-up
//     // BUG: 书写马虎，应该是i>=0 && j<n,竟然错写成了col < n
//     for(int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
//         if(chessboard[i][j] == 'Q')
//             return false;   
//     }
//     // right
//     for(int j = col + 1; j < n; ++j) {
//         if(chessboard[row][j] == 'Q')
//             return false;   
//     }
//     // right-down
//     for(int i = row + 1, j = col + 1; i < n && j < n; ++i, ++j) {
//         if(chessboard[i][j] == 'Q')
//             return false;
//     }
//     // down
//     for(int i = row + 1; i < n; ++i) {
//         if(chessboard[i][col] == 'Q')
//             return false;
//     }
//     // left-down
//     for(int i = row + 1, j = col - 1; i < n && j >= 0; ++i, --j) {
//         if(chessboard[i][j] == 'Q')
//             return false;
//     }
//     // left
//     for(int j = col - 1; j >= 0; --j) {
//         if(chessboard[row][j] == 'Q')
//             return false;   
//     }
//     // left-up
//     for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
//         if(chessboard[i][j] == 'Q')
//             return false;   
//     }
//     return true;
// }

#endif