#ifndef MONOTONE_INCREASING_DIGITS_HPP
#define MONOTONE_INCREASING_DIGITS_HPP

#include <string>
using std::string; using std::to_string; using std::stoi;

/**
 * @brief 找到小于等于当前数字的最大数字，该数字满足各个数位上的数字从前往后是单调递增的
 * @details 1) 前一数位大于当前数位，解决方法是前一数位减一，当前数位变为9;
 * 2) 那么应该从前往后还是从后往前进行遍历呢？应该是从后往前，这样遍历的过程中能够重复利用上一次的比较结果；例如对于332
 * 如果从前往后进行遍历，得到329，仍然不是单调递增的，从后往前就可以得到结果299
 * 3) 对于特殊数字1000，如果按照上述算法得到的就是900，但实际结果应该是999，如何解决呢？定义一个位置索引flag，
 * 用来存储需要设置为‘9’的最高位，只要遍历结束后，从flag位往后都设置为‘9’就好了
 * 4) 将数字转换为字符串进行处理，操作起来更方便一些
 * @note 时间复杂度O(n)；空间复杂度O(1)
*/

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int flag = num.size();  // 最低位的下一位
        // 需要从后往前进行遍历
        for (int i = num.size()-1; i > 0; i--)
        {
            if(num[i] < num[i-1]) {
                --num[i-1];
                flag = i;
            }
        }
        for(int i = flag; i < num.size(); ++i) {
            num[i] = '9';
        }  
        return stoi(num);
    }
};

class Solution_brute_force {
private:
    // 如果是数位是单调递增的，那么从后往前就是大于等于的
    bool checknum(int n) {
        int max = 10;
        while (n)
        {
            int num = n % 10;
            if(max >= num) max = num;
            else return false;
            n /= 10;
        }
        return true;
    }

public:
    int monotoneIncreasingDigits(int n) {
        // 暴力穷举所有的可能性
        for(int num = n; num > 0; --num) {
            if(checknum(num))
                return num;
        }
        return 0;
    }
};

#endif