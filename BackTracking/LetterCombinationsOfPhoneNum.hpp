#ifndef LETTER_COMBINATIONS_OF_PHONE_NUM_HPP
#define LETTER_COMBINATIONS_OF_PHONE_NUM_HPP

#include <vector>
using std::vector;

#include <string>
using std::string; using std::stoi;

// 数字和字母序列采用数组索引与字符串元素的映射
// key: 对于不变量应该声明为const
const string maps[] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

class Solution {
public:
    // 对于不变的标准库对象，应该设置为const string&
    void backTracking(const string &digits, int startIdx, string &comb, vector<string> &result) {
        // 遍历的深度就是目前字母组合字符串的长度
        if(startIdx == digits.size()) {
            result.push_back(comb);
            return;
        }
        // int digit = stoi(digits.substr(startIdx, 1));
        int digit = digits[startIdx] - '0'; // 这也是一种字母转换为数字的方法
        string letters = maps[digit];
        for(int i = 0; i < letters.size(); ++i) {
            comb.push_back(letters[i]);
            backTracking(digits, startIdx + 1, comb, result);
            comb.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        string comb;
        vector<string> result;
        // Bug: 没有考虑到digits为空的情况
        if(digits.empty()) return result;   // 如果没有这个逻辑，当digits为空的时候，result中仍然会push一个空string
        backTracking(digits, 0, comb, result);
        return result;
    }
};

#endif