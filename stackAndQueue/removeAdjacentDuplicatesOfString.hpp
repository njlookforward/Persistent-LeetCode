#ifndef REMOVEADJACENTDUPLICATESINSTRING_HPP
#define REMOVEADJACENTDUPLICATESINSTRING_HPP

#include <stack>
using std::stack;

#include <string>
using std::string;

#include <algorithm>
using std::reverse;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string res;
        for (auto ch : s)
        {
            if(st.empty() || st.top() != ch)
                st.push(ch);
            else
                st.pop();
        }
        // 这样的写法太慢了
        // while (!st.empty())
        // {
        //     res.insert(res.begin(), st.top());
        //     st.pop();
        // }
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution_string {
public:
    string removeDuplicates(string s)
    {
        // 算法真是奇妙啊，用结果string作为栈进行添加和删除，空间复杂度为O(1)
        string res;
        for (char ch : s)
        {
            if(res.empty() || res.back() != ch)
                res.push_back(ch);
            else
                res.pop_back();
        }
        return res;   
    }
};

#endif