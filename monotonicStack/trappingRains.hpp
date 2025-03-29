#ifndef TRAPPINGRAINS_HPP
#define TRAPPINGRAINS_HPP

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include <cstddef>
using std::size_t;

#include <algorithm>
using std::min;

// 我更倾向于第一种写法，比起代码精简，代码逻辑清楚更重要
class Solution {
public:
    int trap(vector<int>& height)
    {
        int sum = 0;
        stack<size_t> st;
        for (size_t i = 0; i < height.size(); i++)
        {
            if(st.empty() || height[i] < height[st.top()])
                st.push(i);
            else if(height[i] == height[st.top()])
            {
                st.pop();
                st.push(i);
            } else {
                while (!st.empty() && height[i] > height[st.top()])
                {
                    size_t middle = st.top();
                    st.pop();
                    if(!st.empty()) {
                        int h = min(height[i], height[st.top()]) - height[middle];
                        int w = i - st.top() - 1;
                        sum += h * w;
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
};


class Solution_simplify {
public:
    int trap(vector<int> &height)
    {
        int sum = 0;
        stack<size_t> st;
        for (size_t i = 0; i < height.size(); i++)
        {
            while (!st.empty() && height[i] > height[st.top()])
            {
                size_t middle = st.top();
                st.pop();
                if(!st.empty()) {
                    // 说明存在左侧第一个更大的高度
                    int h = min(height[st.top()], height[i]) - height[middle];
                    int w = i - st.top() - 1;
                    sum += h * w;
                }
            }
            // Bug: 必须判断stack不空，才能使用top and pop function
            if(!st.empty() && height[i] == height[st.top()]) {
                st.pop();
                st.push(i);  // 需要更新索引，得到正确的宽度
            }
            st.push(i);
        }
        return sum;
    }
};

#endif