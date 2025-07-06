#ifndef TRAP_HPP
#define TRAP_HPP

#include <vector>
using std::vector;
#include <algorithm>
using std::min;
using std::max;
#include <stack>
using std::stack;

/**
 * @brief 接雨水，我需要知道每一个部分的左边界多高，右边界多高
 * 1）每次计算边界的时候需要包括自己的高度，否则可能算出负数
 * @note 时间复杂度0(3n)
 * 空间复杂度0(n)
 */
class Solution {
public:
    int trap(vector<int> &height) {
        vector<int> maxLvec(height.size(), 0);
        vector<int> maxRvec(height.size(), 0);
        // 从左到右遍历数组
        int maxL = 0;
        for(int i = 0; i < height.size(); i++) {
            maxL = max(maxL, height[i]);
            maxLvec[i] = maxL;
        }
        // 从右到左遍历数组
        int maxR = 0;
        for(int i = height.size() - 1; i >= 0; i--) {
            maxR = max(maxR, height[i]);
            maxRvec[i] = maxR;
        }

        int res = 0;
        for(int i = 0; i < height.size(); i++) {
            res += min(maxLvec[i], maxRvec[i]) - height[i];
        }

        return res;
    }
};

/**
 * @brief 
 * 1) 需要找到最高的左边界，找到最高的右边界，左边界数组从左到右越来越大，右边界数组从右到左越来越大
 * 因此左边界从左往右遍历，右边界从右往左遍历，根据木桶效应，找到当前的最小值，这就是此时的最大高度，减去自身就是
 * 能够接到的雨水数量
 * 2）数据结构：int maxL; int maxR; left, right, res
 */
class Solution_double_pointer {
public:
    int trap(vector<int> &height) {
        int res = 0;    
        int maxL = height[0], maxR = height[height.size() - 1];
        int left = 0, right = height.size() - 1;
        while(left <= right) {
            if(maxL <= maxR) {
                res += maxL - height[left];
                ++left;
                // bug1: ++left后直接处理新的height[left]，这是不对的
                // 还没有判断left是否在数据边界内，因此可以多循环几次。有些冗余是必要的
                // 一定要注意每次移动数组边界后，一定要判断后再使用
                // maxL = max(maxL, height[left]);
                // 为了防止越界，必须先判断
                if(left < height.size())
                    maxL = max(maxL, height[left]);
            } else {
                res += maxR - height[right];
                --right;
                // maxR = max(maxR, height[right]);
                if(right >= 0)
                    maxR = max(maxR, height[right]);
            }
        }

        return res;
    }
};

class Solution_double_pointer_v2 {
public:
    // 数据结构，双指针更新左右边界，找到左右边界中的最小值
    // 因为边界值必须包含要计算的列的高度值，因此，必须先更新左右边界，再计算雨水值
    int trap(vector<int> &height) {
        if(height.size() <= 2) return 0;
        int leftHeight = height[0], rightHeight = height[height.size() - 1];
        int res = 0;
        for(int left = 0, right = height.size() - 1; left <= right;) {
            while (leftHeight <= rightHeight && left <= right)
            {
                if(leftHeight - height[left] > 0)
                    res += (leftHeight - height[left]);
                ++left;
                if(left < height.size()) {
                    leftHeight = max(leftHeight, height[left]);
                }    
            }
            while (rightHeight <= leftHeight && left <= right)
            {
                if(rightHeight - height[right] > 0)
                    res += rightHeight - height[right];
                --right;
                if(right >= 0) {
                    rightHeight = max(rightHeight, height[right]);
                }
            }
        }

        return res;
    }
};

/**
 * @brief: 需要想清楚问题是什么 -> 如何解决 -> 转换成什么数据结构 -> 如何通过该数据结构的增删查改实现算法解决问题
 * 按照行解决问题：需要找到凹槽在哪，使用单调栈，从栈顶到栈底是从小到大的，这是不变的
 * 1）height[st.top()] > height[i] 入栈
 * 2）height[st.top()] == height[i] 出栈再入栈，必须使用最右面的作为左边界
 * 3）height[st.top()] < height[i] 需要计算雨水面积了
 */
class Solution_monotonic_stack {
public:
    int trap(vector<int> &height) {
        // 因为至少需要三个元素才能形成凹槽，所以
        if(height.size() <= 2) return 0;
        // 本体抽象成两个数据结构
        stack<int> st;
        int sum = 0;
        st.push(0);
        for(int i = 1; i < height.size(); i++) {
            if(height[st.top()] > height[i]) {
                st.push(i);
            } else if(height[st.top()] == height[i]) {
                st.pop();
                st.push(i);
            } else {
                while(height[st.top()] < height[i]) {
                    int mid = st.top();
                    st.pop();
                    if(st.empty()) break;
                    int h = min(height[st.top()], height[i]) - height[mid];
                    int w = i - st.top() - 1;
                    sum += h * w;
                }
                st.push(i);
            }
        }

        return sum;
    }
};

#endif