#ifndef SUDOKU_SOLVER_HPP
#define SUDOKU_SOLVER_HPP

#include <vector>
using std::vector;

class Solution {
public:
    bool backTracking(vector<vector<char>> &board);
    bool isValid(int row, int col, char digit, vector<vector<char>> &board);
    void solveSudoku(vector<vector<char>> &board) {
        backTracking(board);
    }
};

// 数独问题的回溯递归树，横向的每一个树层，为确定该子块使用什么数字，遍历'1'-'9'；
// 纵向递归遍历确定在满足前面递归层的基础上，下一个子块应该填入什么数字，所以单层逻辑中双层for循环仅仅是为了找到
// 该层递归所需要填入数字的子块位置
bool Solution::backTracking(vector<vector<char>> &board) {
    for(int i = 0; i < board.size(); ++i)
        for(int j = 0; j < board[i].size(); ++j)
            if(board[i][j] == '.') {
                for(char k = '1'; k <= '9'; ++k) {
                    if(isValid(i, j, k, board)) {
                        board[i][j] = k;
                        bool result = backTracking(board);
                        if(result) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
    // 纵向的遍历是递归，递归的终止条件是已经遍历完数独的全部子块，说明找到了一组正确的值，然后返回true
    return true;
}

bool Solution::isValid(int row, int col, char digit, vector<vector<char>> &board) {
    // 行
    for(int j = 0; j < board[row].size(); ++j)
        if(board[row][j] == digit)
            return false;
    // 列 
    for(int i = 0; i < board.size(); ++i) 
        if(board[i][col] == digit)
            return false;   
    // 九宫格
    // BUG：逻辑发生错误，对于二维数组要用两层for循环进行遍历
    int gridRow = row / 3 * 3,
        gridCol = col / 3 * 3;
    for(int i = gridRow; i < gridRow + 3; ++i)
        for(int j = gridCol; j < gridCol + 3; ++j)
            if(board[i][j] == digit)
                return false;
    return true;
}

#endif