#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

// question1：头文件保护命令#ifndef 后面的宏是不是不能用数字开头

#include <vector>
using std::vector;

/**
 * @brief 二分查找，因为数组已经有序了，因此可以使用二分查找寻找目标值
 * @details 我喜欢使用左闭右开，还要注意在C++中存在计算后结果溢出的可能
 * @note time: O(logn)  space:O(1)
 */

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if(nums.size() == 0) return -1;
        for(int left = 0, right = nums.size(); left < right; ) {
            int middle = left + ((right - left) >> 1);
            if(nums[middle] == target) 
                return middle;
            else if(nums[middle] < target) {
                left = middle + 1;
            } else 
                right = middle;
        }

        return -1;
    }
};



#endif