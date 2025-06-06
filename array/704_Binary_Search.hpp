#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

// question1：头文件保护命令#ifndef 后面的宏是不是不能用数字开头

#include <vector>
using std::vector;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        // 我按照左闭右开进行处理
        int left = 0, right = nums.size();
        while(left < right) {
            // 为防止(left + right) 溢出，应该使用如下的写法
            int middle = left + ((right - left) >> 1);
            if(nums[middle] == target)  
                return middle;
            else if(nums[middle] > target)
                right = middle;
            else
                left = middle + 1;
        }

        return -1;
    }
};



#endif