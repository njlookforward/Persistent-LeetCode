#ifndef DAILYTEMPERATURE_HPP
#define DAILYTEMPERATURE_HPP

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include <cstddef>
using std::size_t;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> res(temperatures.size(), 0);
        stack<size_t> st;   // key1: store index
        st.push(0);
        for (size_t i = 1; i < temperatures.size(); i++)
        {
            // key2: 遍历的过程比较三种可能出现的情况
            // key3: while not if
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                res[st.top()] = i - st.top();
                st.pop();
            }
            // if(st.empty() || temperatures[i] <= temperatures[st.top()])
            // {
            //     st.push(i);
            // }
            // 精简的代码
            st.push(i);
        }
        
        return res;
    }
};

#endif